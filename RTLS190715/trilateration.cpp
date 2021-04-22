#include <QTableWidgetItem>
#include "trilateration.h"
#include <iostream>
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"
#include <QDebug>
#include <QTime>
#include <Eigen>

using namespace Eigen;
using namespace std;

/* 近似为0 */
#define   MAXZERO  0.001

// 同心圆问题
#define		ERR_TRIL_CONCENTRIC						-1
#define		ERR_TRIL_COLINEAR_2SOLUTIONS			-2
#define		ERR_TRIL_SQRTNEGNUMB					-3
#define		ERR_TRIL_NOINTERSECTION_SPHERE4			-4
#define		ERR_TRIL_NEEDMORESPHERE					-5


/*变量定义*/
// 基站坐标
vec3d Anchor[4];

// 标签距离基站距离
ta_dist distance[8];

// 距离标志位
unsigned char dist_flag;

// 标签坐标
vec3d Tag[8];

// 缓存数据
ta_dist dit_temp[8][30];


/* 返回向量减法, (vector1 - vector2). */
vec3d vdiff(const vec3d vector1, const vec3d vector2)
{
    vec3d v;
    v.x = vector1.x - vector2.x;
    v.y = vector1.y - vector2.y;
    v.z = vector1.z - vector2.z;
    return v;
}

/* 返回两向量和，(vector1 + vector2) */
vec3d vsum(const vec3d vector1, const vec3d vector2)
{
    vec3d v;
    v.x = vector1.x + vector2.x;
    v.y = vector1.y + vector2.y;
    v.z = vector1.z + vector2.z;
    return v;
}

/* 向量*常数n. (n*vector)*/
vec3d vmul(const vec3d vector, const double n)
{
    vec3d v;
    v.x = vector.x * n;
    v.y = vector.y * n;
    v.z = vector.z * n;
    return v;
}

/* 向量除以常数n. (vector/n)*/
vec3d vdiv(const vec3d vector, const double n)
{
    vec3d v;
    v.x = vector.x / n;
    v.y = vector.y / n;
    v.z = vector.z / n;
    return v;
}

/* 返回两向量欧氏距离. */
double vdist(const vec3d v1, const vec3d v2)
{
    double xd = v1.x - v2.x;
    double yd = v1.y - v2.y;
    double zd = v1.z - v2.z;
    return sqrt(xd * xd + yd * yd + zd * zd);
}

/* 返回欧几里得范数. */
double vnorm(const vec3d vector)
{
    return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

/* 返回两向量点乘. */
double dot(const vec3d vector1, const vec3d vector2)
{
    return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}

/* Replace vector with its cross product with another vector. */
vec3d cross(const vec3d vector1, const vec3d vector2)
{
    vec3d v;
    v.x = vector1.y * vector2.z - vector1.z * vector2.y;
    v.y = vector1.z * vector2.x - vector1.x * vector2.z;
    v.z = vector1.x * vector2.y - vector1.y * vector2.x;
    return v;
}

/* Return the GDOP (Geometric Dilution of Precision) rate between 0-1.
 * Lower GDOP rate means better precision of intersection.
 */
double gdoprate(const vec3d tag, const vec3d p1, const vec3d p2, const vec3d p3)
{
    vec3d ex, t1, t2, t3;
    double h, gdop1, gdop2, gdop3, result;

    ex = vdiff(p1, tag);
    h = vnorm(ex);
    t1 = vdiv(ex, h);

    ex = vdiff(p2, tag);
    h = vnorm(ex);
    t2 = vdiv(ex, h);

    ex = vdiff(p3, tag);
    h = vnorm(ex);
    t3 = vdiv(ex, h);

    gdop1 = fabs(dot(t1, t2));
    gdop2 = fabs(dot(t2, t3));
    gdop3 = fabs(dot(t3, t1));

    if (gdop1 < gdop2) result = gdop2; else result = gdop1;
    if (result < gdop3) result = gdop3;

    return result;
}

/* Intersecting a sphere sc with radius of r, with a line p1-p2.
 * Return zero if successful, negative error otherwise.
 * mu1 & mu2 are constant to find points of intersection.
*/
int sphereline(const vec3d p1, const vec3d p2, const vec3d sc, double r, double *const mu1, double *const mu2)
{
   double a,b,c;
   double bb4ac;
   vec3d dp;

   dp.x = p2.x - p1.x;
   dp.y = p2.y - p1.y;
   dp.z = p2.z - p1.z;

   a = dp.x * dp.x + dp.y * dp.y + dp.z * dp.z;

   b = 2 * (dp.x * (p1.x - sc.x) + dp.y * (p1.y - sc.y) + dp.z * (p1.z - sc.z));

   c = sc.x * sc.x + sc.y * sc.y + sc.z * sc.z;
   c += p1.x * p1.x + p1.y * p1.y + p1.z * p1.z;
   c -= 2 * (sc.x * p1.x + sc.y * p1.y + sc.z * p1.z);
   c -= r * r;

   bb4ac = b * b - 4 * a * c;

   if (fabs(a) == 0 || bb4ac < 0) {
      *mu1 = 0;
      *mu2 = 0;
      return -1;
   }

   *mu1 = (-b + sqrt(bb4ac)) / (2 * a);
   *mu2 = (-b - sqrt(bb4ac)) / (2 * a);

   return 0;
}

/* Return TRIL_3SPHERES if it is performed using 3 spheres and return
 * TRIL_4SPHERES if it is performed using 4 spheres
 * For TRIL_3SPHERES, there are two solutions: result1 and result2
 * For TRIL_4SPHERES, there is only one solution: best_solution
 *
 * Return negative number for other errors
 *
 * To force the function to work with only 3 spheres, provide a duplicate of
 * any sphere at any place among p1, p2, p3 or p4.
 *
 * The last parameter is the largest nonnegative number considered zero;
 * it is somewhat analogous to machine epsilon (but inclusive).
*/
int trilateration(vec3d *const result1,
                  vec3d *const result2,
                  vec3d *const best_solution,
                  const vec3d p1, const double r1,
                  const vec3d p2, const double r2,
                  const vec3d p3, const double r3,
                  const vec3d p4, const double r4,
                  const double maxzero)
{
    // ex 两圆心之间的距离（向量）
    vec3d	ex, ey, ez, t1, t2, t3;
    // h 圆心欧式距离
    double	h, i, j, x, y, z, t;
    double	mu1=0, mu2=0, mu;
    int result;

    /***********前三个球确定两个点 **********/

    // 如果前三个圆中，就有两个同心圆。计算无法进行，返回-1报错
    // then the calculation may not continue, drop it with error -1

    /* h = |p3 - p1|, ex = (p3 - p1) / |p3 - p1| */
    ex = vdiff(p3, p1); // vector p13
    h = vnorm(ex); // scalar p13
    if (h <= maxzero) {
        /* p1 and p3 are concentric, not good to obtain a precise intersection point */
        //printf("concentric13 return -1\n");
        return ERR_TRIL_CONCENTRIC;
    }

    /* h = |p3 - p2|, ex = (p3 - p2) / |p3 - p2| */
    ex = vdiff(p3, p2); // vector p23
    h = vnorm(ex); // scalar p23
    if (h <= maxzero) {
        /* p2 and p3 are concentric, not good to obtain a precise intersection point */
        //printf("concentric23 return -1\n");
        return ERR_TRIL_CONCENTRIC;
    }

    /* h = |p2 - p1|, ex = (p2 - p1) / |p2 - p1| */
    ex = vdiff(p2, p1); // vector p12
    h = vnorm(ex); // scalar p12
    if (h <= maxzero) {
        return ERR_TRIL_CONCENTRIC;
    }
    // 单位向量
    ex = vdiv(ex, h); // unit vector ex with respect to p1 (new coordinate system)

    /* t1 = p3 - p1, t2 = ex (ex . (p3 - p1)) */
    t1 = vdiff(p3, p1); // vector p13
    i = dot(ex, t1); // the scalar（标量） of t1 on the ex direction
    t2 = vmul(ex, i); // colinear vector to p13 with the length of i

    /* ey = (t1 - t2), t = |t1 - t2| */
    ey = vdiff(t1, t2); // vector t21 perpendicular to t1
    t = vnorm(ey); // scalar t21
    if (t > maxzero) {
        /* ey = (t1 - t2) / |t1 - t2| */
        ey = vdiv(ey, t); // unit vector ey with respect to p1 (new coordinate system)

        /* j = ey . (p3 - p1) */
        j = dot(ey, t1); // scalar t1 on the ey direction
    } else
        j = 0.0;

    /* Note: t <= maxzero implies j = 0.0. */
    if (fabs(j) <= maxzero) {

        /* Is point p1 + (r1 along the axis) the intersection? */
        t2 = vsum(p1, vmul(ex, r1));
        if (fabs(vnorm(vdiff(p2, t2)) - r2) <= maxzero &&
            fabs(vnorm(vdiff(p3, t2)) - r3) <= maxzero) {
            /* Yes, t2 is the only intersection point. */
            if (result1)
                *result1 = t2;
            if (result2)
                *result2 = t2;
            return TRIL_3SPHERES;
        }

        /* Is point p1 - (r1 along the axis) the intersection? */
        t2 = vsum(p1, vmul(ex, -r1));
        if (fabs(vnorm(vdiff(p2, t2)) - r2) <= maxzero &&
            fabs(vnorm(vdiff(p3, t2)) - r3) <= maxzero) {
            /* Yes, t2 is the only intersection point. */
            if (result1)
                *result1 = t2;
            if (result2)
                *result2 = t2;
            return TRIL_3SPHERES;
        }
        /* p1, p2 and p3 are colinear with more than one solution */
        return ERR_TRIL_COLINEAR_2SOLUTIONS;
    }

    /* ez = ex x ey */
    ez = cross(ex, ey); // unit vector ez with respect to p1 (new coordinate system)

    x = (r1*r1 - r2*r2) / (2*h) + h / 2;
    y = (r1*r1 - r3*r3 + i*i) / (2*j) + j / 2 - x * i / j;
    z = r1*r1 - x*x - y*y;
    if (z < -maxzero) {
        /* The solution is invalid, square root of negative number */
        return ERR_TRIL_SQRTNEGNUMB;
    } else
    if (z > 0.0)
        z = sqrt(z);
    else
        z = 0.0;

    /* t2 = p1 + x ex + y ey */
    t2 = vsum(p1, vmul(ex, x));
    t2 = vsum(t2, vmul(ey, y));

    /* result1 = p1 + x ex + y ey + z ez */
    if (result1)
        *result1 = vsum(t2, vmul(ez, z));

    /* result1 = p1 + x ex + y ey - z ez */
    if (result2)
        *result2 = vsum(t2, vmul(ez, -z));

    /*********** 从前三个圆找到两个点结束 **********/
    /********* RESULT1 AND RESULT2 是两个解, 否则返回错误 *********/


    /************* FINDING ONE SOLUTION BY INTRODUCING ONE MORE SPHERE ***********/
    /************* 引入一个新的圆以寻找最优解 ***********/

    // check for concentricness of sphere 4 to sphere 1, 2 and 3
    // if it is concentric to one of them, then sphere 4 cannot be used
    // to determine the best solution and return -1

    /* h = |p4 - p1|, ex = (p4 - p1) / |p4 - p1| */
    ex = vdiff(p4, p1); // vector p14
    h = vnorm(ex); // scalar p14
    if (h <= maxzero) {
        /* p1 and p4 are concentric, not good to obtain a precise intersection point */
        //printf("concentric14 return 0\n");
        return TRIL_3SPHERES;
    }
    /* h = |p4 - p2|, ex = (p4 - p2) / |p4 - p2| */
    ex = vdiff(p4, p2); // vector p24
    h = vnorm(ex); // scalar p24
    if (h <= maxzero) {
        /* p2 and p4 are concentric, not good to obtain a precise intersection point */
        //printf("concentric24 return 0\n");
        return TRIL_3SPHERES;
    }
    /* h = |p4 - p3|, ex = (p4 - p3) / |p4 - p3| */
    ex = vdiff(p4, p3); // vector p34
    h = vnorm(ex); // scalar p34
    if (h <= maxzero) {
        /* p3 and p4 are concentric, not good to obtain a precise intersection point */
        //printf("concentric34 return 0\n");
        return TRIL_3SPHERES;
    }

    // if sphere 4 is not concentric to any sphere, then best solution can be obtained
    /* find i as the distance of result1 to p4 */
    t3 = vdiff(*result1, p4);
    i = vnorm(t3);
    /* find h as the distance of result2 to p4 */
    t3 = vdiff(*result2, p4);
    h = vnorm(t3);

    /* pick the result1 as the nearest point to the center of sphere 4 */
    if (i > h) {
        *best_solution = *result1;
        *result1 = *result2;
        *result2 = *best_solution;
    }

    int count4 = 0;
    double rr4 = r4;
    result = 1;
    /* intersect result1-result2 vector with sphere 4 */
    while(result && count4 < 10)
    {
        result=sphereline(*result1, *result2, p4, rr4, &mu1, &mu2);
        rr4+=0.1;
        count4++;
    }

    if (result) {

        /* No intersection between sphere 4 and the line with the gradient of result1-result2! */
        *best_solution = *result1; // result1 is the closer solution to sphere 4
        //return ERR_TRIL_NOINTERSECTION_SPHERE4;

    } else {

        if (mu1 < 0 && mu2 < 0) {

            /* if both mu1 and mu2 are less than 0 */
            /* result1-result2 line segment is outside sphere 4 with no intersection */
            if (fabs(mu1) <= fabs(mu2)) mu = mu1; else mu = mu2;
            /* h = |result2 - result1|, ex = (result2 - result1) / |result2 - result1| */
            ex = vdiff(*result2, *result1); // vector result1-result2
            h = vnorm(ex); // scalar result1-result2
            ex = vdiv(ex, h); // unit vector ex with respect to result1 (new coordinate system)
            /* 50-50 error correction for mu */
            mu = 0.5*mu;
            /* t2 points to the intersection */
            t2 = vmul(ex, mu*h);
            t2 = vsum(*result1, t2);
            /* the best solution = t2 */
            *best_solution = t2;

        } else if ((mu1 < 0 && mu2 > 1) || (mu2 < 0 && mu1 > 1)) {

            /* if mu1 is less than zero and mu2 is greater than 1, or the other way around */
            /* result1-result2 line segment is inside sphere 4 with no intersection */
            if (mu1 > mu2) mu = mu1; else mu = mu2;
            /* h = |result2 - result1|, ex = (result2 - result1) / |result2 - result1| */
            ex = vdiff(*result2, *result1); // vector result1-result2
            h = vnorm(ex); // scalar result1-result2
            ex = vdiv(ex, h); // unit vector ex with respect to result1 (new coordinate system)
            /* t2 points to the intersection */
            t2 = vmul(ex, mu*h);
            t2 = vsum(*result1, t2);
            /* vector t2-result2 with 50-50 error correction on the length of t3 */
            t3 = vmul(vdiff(*result2, t2),0.5);
            /* the best solution = t2 + t3 */
            *best_solution = vsum(t2, t3);

        } else if (((mu1 > 0 && mu1 < 1) && (mu2 < 0 || mu2 > 1))
                || ((mu2 > 0 && mu2 < 1) && (mu1 < 0 || mu1 > 1))) {

            /* if one mu is between 0 to 1 and the other is not */
            /* result1-result2 line segment intersects sphere 4 at one point */
            if (mu1 >= 0 && mu1 <= 1) mu = mu1; else mu = mu2;
            /* add or subtract with 0.5*mu to distribute error equally onto every sphere */
            if (mu <= 0.5) mu-=0.5*mu; else mu-=0.5*(1-mu);
            /* h = |result2 - result1|, ex = (result2 - result1) / |result2 - result1| */
            ex = vdiff(*result2, *result1); // vector result1-result2
            h = vnorm(ex); // scalar result1-result2
            ex = vdiv(ex, h); // unit vector ex with respect to result1 (new coordinate system)
            /* t2 points to the intersection */
            t2 = vmul(ex, mu*h);
            t2 = vsum(*result1, t2);
            /* the best solution = t2 */
            *best_solution = t2;

        } else if (mu1 == mu2) {

            /* if both mu1 and mu2 are between 0 and 1, and mu1 = mu2 */
            /* result1-result2 line segment is tangential to sphere 4 at one point */
            mu = mu1;
            /* add or subtract with 0.5*mu to distribute error equally onto every sphere */
            if (mu <= 0.25) mu-=0.5*mu;
            else if (mu <=0.5) mu-=0.5*(0.5-mu);
            else if (mu <=0.75) mu-=0.5*(mu-0.5);
            else mu-=0.5*(1-mu);
            /* h = |result2 - result1|, ex = (result2 - result1) / |result2 - result1| */
            ex = vdiff(*result2, *result1); // vector result1-result2
            h = vnorm(ex); // scalar result1-result2
            ex = vdiv(ex, h); // unit vector ex with respect to result1 (new coordinate system)
            /* t2 points to the intersection */
            t2 = vmul(ex, mu*h);
            t2 = vsum(*result1, t2);
            /* the best solution = t2 */
            *best_solution = t2;

        } else {

            /* if both mu1 and mu2 are between 0 and 1 */
            /* result1-result2 line segment intersects sphere 4 at two points */

            //return ERR_TRIL_NEEDMORESPHERE;

            mu = mu1 + mu2;
            /* h = |result2 - result1|, ex = (result2 - result1) / |result2 - result1| */
            ex = vdiff(*result2, *result1); // vector result1-result2
            h = vnorm(ex); // scalar result1-result2
            ex = vdiv(ex, h); // unit vector ex with respect to result1 (new coordinate system)
            /* 50-50 error correction for mu */
            mu = 0.5*mu;
            /* t2 points to the intersection */
            t2 = vmul(ex, mu*h);
            t2 = vsum(*result1, t2);
            /* the best solution = t2 */
            *best_solution = t2;

        }

    }

    return TRIL_4SPHERES;

    /******** END OF FINDING ONE SOLUTION BY INTRODUCING ONE MORE SPHERE *********/
}


/* This function calls trilateration to get the best solution.
 *
 * If any three spheres does not produce valid solution,
 * then each distance is increased to ensure intersection to happens.
 *
 * Return the selected trilateration mode between TRIL_3SPHERES or TRIL_4SPHERES
 * For TRIL_3SPHERES, there are two solutions: solution1 and solution2
 * For TRIL_4SPHERES, there is only one solution: best_solution
 *
 * nosolution_count = the number of failed attempt before intersection is found
 * by increasing the sphere diameter.(失败次数)
 */
int deca_3dlocate (	vec3d	*const solution1,
                    vec3d	*const solution2,
                    vec3d	*const best_solution,
                    int		*const nosolution_count,
                    double	*const best_3derror,
                    double	*const best_gdoprate,
                    vec3d p1, double r1,
                    vec3d p2, double r2,
                    vec3d p3, double r3,
                    vec3d p4, double r4,
                    int *combination)
{
    vec3d	o1, o2, solution, ptemp;
    vec3d	solution_compare1, solution_compare2;
    double	/*error_3dcompare1, error_3dcompare2,*/ rtemp;
    double	gdoprate_compare1, gdoprate_compare2;
    double	ovr_r1, ovr_r2, ovr_r3, ovr_r4;
    int		overlook_count, combination_counter;
    int		trilateration_errcounter, trilateration_mode34;
    int		success, concentric, result;

    trilateration_errcounter = 0;
    trilateration_mode34 = 0;

    combination_counter = 4; /* four spheres combination */

    *best_gdoprate = 1; /* put the worst gdoprate init */
    gdoprate_compare1 = 1; gdoprate_compare2 = 1;
    solution_compare1.x = 0; solution_compare1.y = 0; solution_compare1.z = 0;
    //error_3dcompare1 = 0;

    do {
        success = 0;
        concentric = 0;
        overlook_count = 0;
        ovr_r1 = r1; ovr_r2 = r2; ovr_r3 = r3; ovr_r4 = r4;

        do {
            // 定位算法
            result = trilateration(&o1, &o2, &solution, p1, ovr_r1, p2, ovr_r2, p3, ovr_r3, p4, ovr_r4, MAXZERO);

            switch (result)
            {
                case TRIL_3SPHERES: // 3 spheres are used to get the result
                    trilateration_mode34 = TRIL_3SPHERES;
                    success = 1;
                    break;

                case TRIL_4SPHERES: // 4 spheres are used to get the result
                    trilateration_mode34 = TRIL_4SPHERES;
                    success = 1;
                    break;

                case ERR_TRIL_CONCENTRIC:
                    concentric = 1;
                    break;

                default: // any other return value goes here
                    ovr_r1 += 0.10;
                    ovr_r2 += 0.10;
                    ovr_r3 += 0.10;
                    ovr_r4 += 0.10;
                    overlook_count++;
                    break;
            }

            //qDebug() << "while(!success)" << overlook_count << concentric << "result" << result;

        } while (!success && (overlook_count <= 5) && !concentric);


        if (success)
        {
            switch (result)
            {
            case TRIL_3SPHERES:
                *solution1 = o1;
                *solution2 = o2;
                *nosolution_count = overlook_count;

                combination_counter = 0;
                break;

            case TRIL_4SPHERES:
                /* calculate the new gdop */
                gdoprate_compare1	= gdoprate(solution, p1, p2, p3);

                /* compare and swap with the better result */
                if (gdoprate_compare1 <= gdoprate_compare2) {

                    *solution1 = o1;
                    *solution2 = o2;
                    *best_solution	= solution;
                    *nosolution_count = overlook_count;
                    *best_3derror	= sqrt((vnorm(vdiff(solution, p1))-r1)*(vnorm(vdiff(solution, p1))-r1) +
                                        (vnorm(vdiff(solution, p2))-r2)*(vnorm(vdiff(solution, p2))-r2) +
                                        (vnorm(vdiff(solution, p3))-r3)*(vnorm(vdiff(solution, p3))-r3) +
                                        (vnorm(vdiff(solution, p4))-r4)*(vnorm(vdiff(solution, p4))-r4));
                    *best_gdoprate	= gdoprate_compare1;

                    /* save the previous result */
                    solution_compare2 = solution_compare1;
                    //error_3dcompare2 = error_3dcompare1;
                    gdoprate_compare2 = gdoprate_compare1;

                    *combination = 5 - combination_counter;

                    ptemp = p1; p1 = p2; p2 = p3; p3 = p4; p4 = ptemp;
                    rtemp = r1; r1 = r2; r2 = r3; r3 = r4; r4 = rtemp;
                    combination_counter--;
                }
                else
                    combination_counter=0;
                break;

            default:
                break;
            }
        }
        else
        {
            //trilateration_errcounter++;
            trilateration_errcounter = 4;
            combination_counter = 0;
        }

        //ptemp = p1; p1 = p2; p2 = p3; p3 = p4; p4 = ptemp;
        //rtemp = r1; r1 = r2; r2 = r3; r3 = r4; r4 = rtemp;
        //combination_counter--;
        //qDebug() << "while(combination_counter)" << combination_counter;

    } while (combination_counter);

    // if it gives error for all 4 sphere combinations then no valid result is given
    // otherwise return the trilateration mode used
    if (trilateration_errcounter >= 4) return -1; else return trilateration_mode34;

}

// 测距函数 GetLocation
// best_solution返回值指针（结果为Tag坐标）
// use4thAnchor 是否使用第四个基站（标志位）
// anchorArray 基站列表
// distanceArray 距离列表
int GetLocationTrilateral(vec3d *best_solution, int use4thAnchor, vec3d* anchorArray, int *distanceArray)
{

    // o1、o2两个解，p1-p4基站坐标，r1-r4距离，
    vec3d	o1, o2, p1, p2, p3, p4;
    double	r1 = 0, r2 = 0, r3 = 0, r4 = 0, best_3derror, best_gdoprate;
    int		result;
    int     error, combination;

    vec3d	t3;
    double	dist1, dist2;

    /* Anchors coordinate */
    p1.x = anchorArray[0].x;		p1.y = anchorArray[0].y;	p1.z = anchorArray[0].z;
    p2.x = anchorArray[1].x;		p2.y = anchorArray[1].y;	p2.z = anchorArray[1].z;
    p3.x = anchorArray[2].x;		p3.y = anchorArray[2].y;	p3.z = anchorArray[2].z;
    p4.x = anchorArray[0].x;		p4.y = anchorArray[0].y;	p4.z = anchorArray[0].z; //4th same as 1st - only 3 used for trilateration

    r1 = double(distanceArray[0] / 1000.0);
    r2 = double(distanceArray[1] / 1000.0);
    r3 = double(distanceArray[2] / 1000.0);

    r4 = double(distanceArray[3] / 1000.0);


    /* get the best location using 3 or 4 spheres and keep it as know_best_location */
    result = deca_3dlocate (&o1, &o2, best_solution, &error, &best_3derror, &best_gdoprate,
                            p1, r1, p2, r2, p3, r3, p4, r1, &combination);

    if(result >= 0)
    {
        if (use4thAnchor == 1) //if have 4 ranging results, then use 4th anchor to pick solution closest to it
        {
                double diff1, diff2;
                /* find dist1 as the distance of o1 to known_best_location */
                t3 = vdiff(o1, anchorArray[3]);
                dist1 = vnorm(t3);

                t3 = vdiff(o2, anchorArray[3]);
                dist2 = vnorm(t3);

                /* find the distance closest to received range measurement from 4th anchor */
                diff1 = fabs(r4 - dist1);
                diff2 = fabs(r4 - dist2);

                /* pick the closest match to the 4th anchor range */
                if (diff1 < diff2) *best_solution = o1; else *best_solution = o2;
        }
        else
        {
            //assume tag is below the anchors (1, 2, and 3)
            if(o1.z < p1.z) *best_solution = o1; else *best_solution = o2;
//            if(o1.z > p1.z) *best_solution = o1; else *best_solution = o2;
        }
    }

    if (result >= 0)
    {
        return result;
    }

    //return error
    return -1;
}

// 测试
void test(void)
{
    int result = 0;
    vec3d anchorArray[4];
    vec3d report;
    int Range_deca[4];

    anchorArray[0].x = -0.50; //anchor0.x uint:m
    anchorArray[0].y = 0.000; //anchor0.y uint:m
    anchorArray[0].z = 0.000; //anchor0.z uint:m

    anchorArray[1].x = 4.200; //anchor1.x uint:m
    anchorArray[1].y = -2.40; //anchor1.y uint:m
    anchorArray[1].z = 0.700; //anchor1.z uint:m

    anchorArray[2].x = -3.70; //anchor2.x uint:m
    anchorArray[2].y = 0.450; //anchor2.y uint:m
    anchorArray[2].z = 1.700; //anchor2.z uint:m

    anchorArray[3].x = 1.000; //anchor3.x uint:m
    anchorArray[3].y = 0.000; //anchor3.y uint:m
    anchorArray[3].z = 0.700; //anchor3.z uint:m

    RigidMotionInit(&anchorArray[0]);
    vec3d loc1 = CoordinateTranformation(W2V, &anchorArray[0]);
    cout << loc1.x << endl;
    cout << loc1.y << endl;
    cout << loc1.z << endl;
    loc1 = CoordinateTranformation(W2V, &anchorArray[1]);
    cout << loc1.x << endl;
    cout << loc1.y << endl;
    cout << loc1.z << endl;
    loc1 = CoordinateTranformation(W2V, &anchorArray[2]);
    cout << loc1.x << endl;
    cout << loc1.y << endl;
    cout << loc1.z << endl;

    Range_deca[0] = 4740; //tag to A0 distance
    Range_deca[1] = 8628; //tag to A1 distance
    Range_deca[2] = 5254; //tag to A2 distance
    Range_deca[3] = 4889; //tag to A3 distance

    result = GetLocationTrilateral(&report, 1, &anchorArray[0], &Range_deca[0]);
    printf("result = %d\r\n", result);
    printf("tag.x=%.3f\r\ntag.y=%.3f\r\ntag.z=%.3f\r\n", report.x, report.y, report.z);

    QTime t;
    t.start();
    MatrixXd Q = MatrixXd::Identity(4, 4) * 0.0025; // sd = 0.05
    GetLocationChanTaylor(&report, &anchorArray[0], &Range_deca[0], Q, 100, 0.0001, 150);
    printf("tag.x=%.3f\r\ntag.y=%.3f\r\ntag.z=%.3f\r\n", report.x, report.y, report.z);
    qDebug()<<t.elapsed()<<"ms";
}



// Chan-Taylor测距
void GetLocationChanTaylor(vec3d *best_solution, vec3d* anchorArray, int *distanceArray, MatrixXd Q, double residual, double delta, int iterativeNum)
{
    cout << "C-T-K~" << endl;
    /*  获取初始位置Chan  */
    // 初始位置
    vec3d locationInit;
    locationInit = Chan(anchorArray, distanceArray, Q);
    *best_solution = locationInit;

    /*  计算残差  */
    double residualCal = 0;
    residualCal = ResidualCal(anchorArray, best_solution, distanceArray);
    qDebug()<<"ResidualCal:"<<residualCal<<endl;

    /*  判断是否要进行Taylor  */
    if (residualCal > residual)
        *best_solution = TaylorItrator(anchorArray, &locationInit, distanceArray, Q, delta, iterativeNum);
    else
        *best_solution = locationInit;

}

// C-T-K
void GetLocationChanTaylorKalman(vec3d *best_solution, vec3d *anchorArray, int *distanceArray, KalmanFilter* kf, MatrixXd Q, double residual, double delta, int iterativeNum)
{
    qDebug() << "C-T-K positioning~" <<endl;
    /*  获取初始位置Chan  */
    // 初始位置
    vec3d locationInit;
    locationInit = Chan(anchorArray, distanceArray, Q);
    *best_solution = locationInit;

    /*  计算残差  */
    double residualCal = 0;
    residualCal = ResidualCal(anchorArray, best_solution, distanceArray);
    qDebug()<<"ResidualCal:"<<residualCal<<endl;

    /*  Taylor  */
    locationInit = TaylorItrator(anchorArray, best_solution, distanceArray, Q, delta, iterativeNum);
    if (isnan(locationInit.x) || isnan(locationInit.y) || isnan(locationInit.z)) {
        cout << "warning: taylor nan!" << endl;
    } else {
        *best_solution = locationInit;
    }
    // 卡尔曼滤波
    kf->iteration(best_solution);
}

// TS(三边) - T - K
void GetLocationTrilateralTaylorKalman(vec3d *best_solution, vec3d *anchorArray, int *distanceArray, KalmanFilter* kf, MatrixXd Q, double residual, double delta, int iterativeNum){
    cout << "T-T-K~" << endl;
    // 0.检测旋转逆矩阵、平移矩阵是否初始化
    if (!rigid_motion.flag) {
        RigidMotionInit(anchorArray);
    }
    // 1.坐标变换
    vec3d anchorArrayPlane[4];
    for (int i = 0; i < 4; i++) {
        anchorArrayPlane[i] = CoordinateTranformation(W2V, &anchorArray[i]);
    }
    // 2.三边测距
    GetLocationTrilateral(best_solution, 1, &anchorArrayPlane[0], distanceArray);
    *best_solution = CoordinateTranformation(V2W, best_solution);
    vec3d locationInit = *best_solution;
    // 3.Taylor
    /*  计算残差  */
    double residualCal = 0;
    residualCal = ResidualCal(anchorArray, best_solution, distanceArray);
    qDebug()<<"ResidualCal: "<<residualCal<<endl;

    /*  Taylor  */
    locationInit = TaylorItrator(anchorArray, best_solution, distanceArray, Q, delta, iterativeNum);
    if (isnan(locationInit.x) || isnan(locationInit.y) || isnan(locationInit.z)) {
        cout << "warning: taylor nan!" << endl;
    } else {
        *best_solution = locationInit;
    }
    // 4.Kalman
    kf->iteration(best_solution);
}

// 旋转矩阵、平移矩阵初始化
void RigidMotionInit(vec3d *anchorArray) {
    // A0 - A2
    vec3d a0 = anchorArray[0];
    vec3d a1 = anchorArray[1];
    vec3d a2 = anchorArray[2];
    // A0_A1 => x轴单位向量 x
    vec3d x = vdiff(a0, a1);
    x = vdiv(x, vnorm(x));
    // A0_A2 => A0_A2 单位向量t
    vec3d t = vdiff(a0, a2);
    t = vdiv(t, vnorm(t));
    // t1在x上的投影向量 t2x
    vec3d t2x = vmul(x, dot(x, t));
    // 向量y
    vec3d y = vdiff(t, t2x);
    y = vdiv(y, vnorm(y));
    // 向量z
    vec3d z = cross(x, y);
    // 旋转矩阵、平移矩阵初始化
    rigid_motion.flag = true;
    // 旋转逆矩阵
    // V2W
    rigid_motion.R_w2v(0, 0) = x.x;
    rigid_motion.R_w2v(0, 1) = x.y;
    rigid_motion.R_w2v(0, 2) = x.z;
    rigid_motion.R_w2v(1, 0) = y.x;
    rigid_motion.R_w2v(1, 1) = y.y;
    rigid_motion.R_w2v(1, 2) = y.z;
    rigid_motion.R_w2v(2, 0) = z.x;
    rigid_motion.R_w2v(2, 1) = z.y;
    rigid_motion.R_w2v(2, 2) = z.z;
    // W2V
    rigid_motion.R_v2w = rigid_motion.R_w2v.transpose();
    // 平移矩阵
    // V2W
    rigid_motion.t_w2v(0, 0) = -anchorArray[0].x;
    rigid_motion.t_w2v(1, 0) = -anchorArray[0].y;
    rigid_motion.t_w2v(2, 0) = -anchorArray[0].z;
    // W2V
    rigid_motion.t_v2w = - rigid_motion.t_w2v;

    rigid_motion.t_w2v = rigid_motion.R_w2v * rigid_motion.t_w2v;
}

// 坐标点转化
vec3d CoordinateTranformation(int mode, vec3d *loc) {
    // 转化为矩阵
    MatrixXd originLoc(3, 1), targetLoc;
    originLoc(0, 0) = loc->x;
    originLoc(1, 0) = loc->y;
    originLoc(2, 0) = loc->z;
    if (mode == W2V) {
        targetLoc = rigid_motion.R_w2v * originLoc + rigid_motion.t_w2v;
    } else if (mode == V2W) {
        targetLoc = rigid_motion.R_v2w * originLoc + rigid_motion.t_v2w;
    }
    vec3d target;
    target.x = targetLoc(0, 0);
    target.y = targetLoc(1, 0);
    target.z = targetLoc(2, 0);
    return target;
}

// Chan方法
vec3d Chan(vec3d* anchorArray, int *distanceArray, MatrixXd Q)
{
    // xyz赋值
    // typedef Matrix<double, Dynamic, Dynamic> MatrixXd;
    // (double类型)
    // 坐标和距离单统一(mm)
    Q = Q * 1000000;
    MatrixXd x(4,1);
    MatrixXd y(4,1);
    MatrixXd z(4,1);
    for(int i =0;i<4;i++){
        x(i,0) = anchorArray[i].x * 1000.0;
        y(i,0) = anchorArray[i].y * 1000.0;
        z(i,0) = anchorArray[i].z * 1000.0;
    }

    // 运算结果
    MatrixXd result;
    vec3d location;

    // 误差矢量 Ψ = h - Gz
    // h、G参数赋值
    MatrixXd h(4,1);
    MatrixXd G(4,4);
    MatrixXd B(4,4);
    MatrixXd Psi_inv;
    for(int i=0;i<4;i++)
    {
        h(i,0) = distanceArray[i]*distanceArray[i] - x(i, 0)*x(i, 0)- y(i, 0)*y(i, 0)- z(i, 0)*z(i, 0);
        // TODO 行赋值操作
        G(i, 0) = -2*x(i,0);
        G(i, 1) = -2*y(i,0);
        G(i, 2) = -2*z(i,0);
        G(i, 3) = 1;
        B(i, i) = distanceArray[i];
    }
    Psi_inv =  (4 * B * Q * B).inverse();
    // 计算并输出结果
    result = (G.transpose()*Psi_inv*G).inverse()*G.transpose()*Psi_inv*h;
    location.x = result(0, 0) / 1000;
    location.y = result(1, 0) / 1000;
    location.z = result(2, 0) / 1000;
    return location;
}

// Taylor迭代定位
// 500次67ms  1次0.134ms
vec3d TaylorItrator(vec3d* anchorArray, vec3d* location, int *distanceArray, MatrixXd Q, double delta, int iterativeNum)
{
    qDebug() << "Taylor~" << endl;
    // 坐标
    vec3d locaItrator = *location;
    // 坐标偏差
    vec3d locationDelta;
    // 迭代中残差
    double deltaCal;
    // 迭代次数
    int i;

    // 循环执行知道delta满足条件或者迭代超过次数
    for (i =0;i<iterativeNum;i++)
    {
        locationDelta = Taylor(anchorArray, &locaItrator, distanceArray, Q);
        locaItrator.x += locationDelta.x;
        locaItrator.y += locationDelta.y;
        locaItrator.z += locationDelta.z;
        deltaCal = sqrt(locationDelta.x*locationDelta.x + locationDelta.y*locationDelta.y + locationDelta.z*locationDelta.z);
        if (deltaCal <= delta)
            break;
    }
    qDebug()<<"迭代次数："<<i<<endl;
    return locaItrator;
}

// Taylor定位
vec3d Taylor(vec3d* anchorArray, vec3d* location, int *distanceArray, MatrixXd Q)
{
    // 求迭代的distance
    double distanceUpdata[4];
    distUpdata(anchorArray, location, distanceUpdata);  // 函数内已进行单位mm统一
    Q = Q * 1000000;

    // h G 参数(单位统mm)
    MatrixXd h(4,1);
    MatrixXd G(4,3);
    for (int i=0;i<4;i++)
    {
        h(i,0) = distanceArray[i] - distanceUpdata[i];
        G(i,0) = 1000 * (location->x - anchorArray[i].x)/distanceUpdata[i];
        G(i,1) = 1000 * (location->y - anchorArray[i].y)/distanceUpdata[i];
        G(i,2) = 1000 * (location->z - anchorArray[i].z)/distanceUpdata[i];
    }

    // 加权最小二乘法求解
    vec3d locationDelta;
    MatrixXd delta(3,1);
    delta = (G.transpose()*Q.inverse()*G).inverse()*(G.transpose()*Q.inverse()*h);

    locationDelta.x = delta(0,0)/1000;
    locationDelta.y = delta(1,0)/1000;
    locationDelta.z = delta(2,0)/1000;
    return locationDelta;
}

// 求迭代的distance
void distUpdata(vec3d* anchorArray, vec3d* location, double *distanceUd)
{
    // 单位统一(mm)
    for (int i=0;i < 4;i++)
    {
        distanceUd[i] = sqrt((anchorArray[i].x-location->x)*(anchorArray[i].x-location->x)
                             + (anchorArray[i].y-location->y)*(anchorArray[i].y-location->y)
                             + (anchorArray[i].z-location->z)*(anchorArray[i].z-location->z));
        distanceUd[i] *= 1000;
    }
}

// 残差计算
double ResidualCal(vec3d* anchorArray, vec3d* location, int *distanceArray)
{
    // 残差
    double residual = 0;
    double difference = 0;

    for (int i=0;i<4;i++)
    {
        difference = sqrt((anchorArray[i].x-location->x)*(anchorArray[i].x-location->x)
                         + (anchorArray[i].y-location->y)*(anchorArray[i].y-location->y)
                         + (anchorArray[i].z-location->z)*(anchorArray[i].z-location->z))
                         - distanceArray[i]/1000.0;
        residual += difference*difference;
        difference = 0;
    }
    return residual;
}


// 根据不同方法，定位
void GetLocation(LocationMethod method, vec3d *best_solution, vec3d *anchorArray, int *distanceArray, KalmanFilter *kf, MatrixXd Q, double residual, double delta, int iterativeNum)
{
    switch (method) {
    case C_T_K:
        GetLocationChanTaylorKalman(best_solution, anchorArray, distanceArray, kf, Q, residual, delta, iterativeNum);
        break;
    case T_T_K:
        GetLocationTrilateralTaylorKalman(best_solution, anchorArray, distanceArray, kf, Q, residual, delta, iterativeNum);
            break;
    case C_T:
        GetLocationChanTaylor(best_solution, anchorArray, distanceArray, Q, residual, delta, iterativeNum);
        break;
    default:
        throw "invalid argument！";
    }
}

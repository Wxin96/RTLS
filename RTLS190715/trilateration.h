#ifndef TRILATERATION_H
#define TRILATERATION_H
#include "basetsd.h"
#include "stdio.h"

#define		TRIL_3SPHERES							3
#define		TRIL_4SPHERES							4

// 坐标结构体
struct vec3d{
    double	x;
    double	y;
    double	z;
    char flag[3];
};

// 标签距离四个基站的距离
struct ta_dist{
    int t_a0;
    int t_a1;
    int t_a2;
    int t_a3;
    // 标志位
    int flag;
};

// 基站坐标
extern vec3d Anchor[4];

// 标签距离基站距离
extern ta_dist distance[8];

// 距离标志位
extern unsigned char dist_flag;

// 标签坐标
extern vec3d Tag[8];

// 缓存数据
extern ta_dist dit_temp[8][30];

/* Return the difference of two vectors, (vector1 - vector2). */
vec3d vdiff(const vec3d vector1, const vec3d vector2);

/* Return the sum of two vectors. */
vec3d vsum(const vec3d vector1, const vec3d vector2);

/* Multiply vector by a number. */
vec3d vmul(const vec3d vector, const double n);

/* Divide vector by a number. */
vec3d vdiv(const vec3d vector, const double n);

/* Return the Euclidean norm. */
double vdist(const vec3d v1, const vec3d v2);

/* Return the Euclidean norm. */
double vnorm(const vec3d vector);

/* Return the dot product of two vectors. */
double dot(const vec3d vector1, const vec3d vector2);

/* Replace vector with its cross product with another vector. */
vec3d cross(const vec3d vector1, const vec3d vector2);

// 测距函数
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
                  const double maxzero);
int GetLocation(vec3d *best_solution, int use4thAnchor, vec3d* anchorArray, int *distanceArray);

void GetLocationChanTaylor(vec3d *best_solution, vec3d* anchorArray, int *distanceArray, double residual, double delta, int iterativeNum);

/* Chan方法初次定位 */
vec3d Chan(vec3d* anchorArray, int *distanceArray);

/* Taylor方法迭代定位 */
vec3d TaylorItrator(vec3d* anchorArray, vec3d* location, int *distanceArray, double delta, int iterativeNum);

/* Taylor方法定位 */
vec3d Taylor(vec3d* anchorArray, vec3d* location, int *distanceArray);

/* Taylor方法定位 */
void distUpdata(vec3d* anchorArray, vec3d* location, double *distanceUd);

double ResidualCal(vec3d* anchorArray, vec3d* location, int *distanceArray);

double vdist(const vec3d v1, const vec3d v2);

void test(void);

#endif // TRILATERATION_H

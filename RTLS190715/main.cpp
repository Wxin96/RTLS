#include "rtls_widget.h"
#include "trilateration.h"
#include <iostream>
#include <QApplication>
#include <QDebug>
#include <Eigen>

using Eigen::MatrixXd;
using namespace std;

int main(int argc, char *argv[])
{
//    Tag[0].x=0;
//    Tag[0].y=0;
//    Tag[0].z=0;

//    MatrixXd m(3,2);
//    m(0,0) = 3;
//    m(1,0) = 2.5;
//    m(0,1) = -1;
//    m(1,1) = m(1,0) + m(0,1);
//    std::cout << m << std::endl;
//    MatrixXd m(4,4);
//    m = MatrixXd::Identity(4, 4);
//    std::cout << m << std::endl;

    // distance数组赋值0
    memset(dit_temp,0,sizeof(dit_temp));

    QApplication a(argc, argv);
    RTLS_Widget w;
    w.show();

    test();

    return a.exec();
}

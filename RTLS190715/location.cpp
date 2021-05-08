#include "location.h"
#include "trilateration.h"
#include <string.h>
#include <QString>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QTimer>
#include <QCheckBox>
#include <QPushButton>


Location::Location(QWidget *parent) : QWidget(parent)
{
    // 窗口名称
    this->setWindowTitle("图形化界面");
    // 定时器
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    timer->start(10);  // 单位：10ms
    // 选择框
    for (int i=0;i<8;i++) {
        QString Qtext = QString("Tag ") + QString::number(i);
        Cbox_t[i] = new QCheckBox(Qtext,this);
        Cbox_t[i]->move(1400,40+20*i);
        connect(Cbox_t[i],&QCheckBox::toggled,this,&Location::QCheckBox_toggled);
    }
}

// 画图事件，虚函数
void Location::paintEvent(QPaintEvent *)
{
    // 绘制坐标
    Location::paint_xy(1280,800);
    // 绘制方格
    Location::paint_grid(80, 80, 16, 10);
    // 画基站
//    Location::paint_rect();
    // 绘制基站
    Location::paint_anchor();
    // 绘制标签
    Location::paint_tag();

}

// CheckBox槽函数
void Location::QCheckBox_toggled()
{
    int num;    // 选中复选框
    QCheckBox* btn = qobject_cast<QCheckBox*>(sender());
    sscanf(btn->text().toUtf8(),"Tag %d", &num);
//    qDebug("%d",num);
    btn->checkState();
    if(btn->checkState()==Qt::Checked)
        tag_flag |= 1<<num;
    else
        tag_flag &= ~(1<<num);
    qDebug("%d",tag_flag);

}

// 刷新画面 => 调用paintEvent函数
void Location::handleTimeout()
{
    update();
}


// 画坐标轴
void Location::paint_xy(int width,int height)
{
    QPainter p;
    p.begin(this);

    // 画笔样式，宽度、颜色、样式
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::black);
    pen.setStyle(Qt::DashDotDotLine);
    p.setPen(pen);
    // 字体
    QFont font;
    font.setPixelSize(25);
    p.setFont(font);

    // 画x轴
    p.drawLine(50,height/2+50,50+width,height/2+50);
    p.drawLine(50+width,height/2+50,45+width,height/2+45);
    p.drawLine(50+width,height/2+50,45+width,height/2+55);
    p.drawText(55+width,height/2+55,"x");
    // 画y轴
    p.drawLine(50+width/2,50,50+width/2,height+50);
    p.drawLine(50+width/2,50,45+width/2,55);
    p.drawLine(50+width/2,50,55+width/2,55);
    p.drawText(57+width/2,57,"y");

    p.end();

    // O点坐标
    Ox = 50 + width/2;
    Oy = 50 + height/2;
//    qDebug("%d,%d",Ox,Oy);
}

// 画网格
void Location::paint_grid(int width,int height, int xn,int yn)
{
    QPainter p(this);
    int i, j;   // 计数变量

    for (i=0;i<xn+1;i++)
    {
        for (j=0;j<yn+1;j++)
        {
            p.drawLine(50+i*width-2, height*j+50,50+i*width+2,height*j+50);
            p.drawLine(50+i*width, height*j+50-2,50+i*width,height*j+50+2);
        }

    }
}


// 绘制矩形
void Location::paint_rect()
{
    QPainter p(this);
    // 画笔样式，宽度、颜色、样式
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    pen.setStyle(Qt::DashDotDotLine);
    p.setPen(pen);

    // 画矩形
//    p.drawPoint(Ox+int(-2*1.13*80), Oy +int(-4*1.13*80));
    p.drawRect(Ox+int(-2*1.13*80), Oy +int(-4*1.13*80), int(6*1.13*80), int(8.7*1.13*80));
}


// 绘制基站坐标
void Location::paint_anchor()
{
    char A0_flag, A1_flag, A2_flag;
    A0_flag = Anchor[0].flag[0] + Anchor[0].flag[1] + Anchor[0].flag[2];
    A1_flag = Anchor[1].flag[0] + Anchor[1].flag[1] + Anchor[1].flag[2];
    A2_flag = Anchor[2].flag[0] + Anchor[2].flag[1] + Anchor[2].flag[2];

//    qDebug("%lf",Anchor[0].x);

    if(A0_flag==3 && A1_flag==3 && A2_flag==3)
    {
        Location::paint_point(Anchor[0].x, Anchor[0].y, 0, 0);
        Location::paint_point(Anchor[1].x, Anchor[1].y, 1, 0);
        Location::paint_point(Anchor[2].x, Anchor[2].y, 2, 0);
        Location::paint_point(Anchor[3].x, Anchor[3].y, 3, 0);
    }
}

// 绘制标签坐标
void Location::paint_tag()
{
    unsigned char temp = tag_flag;

    for (int i=0;i<8;i++)
    {
        if(temp%2 ==1)
        {
            Location::paint_point(Tag[i].x, Tag[i].y, i, 1);
        }
        temp = temp>>1;
    }
}

// 绘制一个点
void Location::paint_point(double x, double y, int id, bool flag)
{
    int x_pix, y_pix;
    char str[80];   // 显示字符串
    QBrush brush;   // 画刷涂点

    x_pix = int(x*80) + Ox;
    y_pix = -int(y*80) + Oy;

    if(flag)
    {
        sprintf(str, "T%d(%2.2lf,%2.2lf)", id, x, y);
        brush.setColor(Qt::green);
    }
    else
    {
        sprintf(str, "A%d(%2.2lf,%2.2lf)", id, x, y);
        brush.setColor(Qt::red);
    }
    QPainter p(this);



    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);

    // 画点
    p.drawEllipse(QPoint(x_pix,y_pix),4,4);
    // 写序号
    // 字体
    QFont font;
    font.setPixelSize(10);
    p.setFont(font);
    p.drawText(QPoint(x_pix+6,y_pix-6),str);

}



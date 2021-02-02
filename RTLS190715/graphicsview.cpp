#include "graphicsview.h"
#include <QPainter>

GraphicsView::GraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{


}

GraphicsView::~GraphicsView()
{

}

void GraphicsView::paintEvent(QPaintEvent *event)
{
//    QGraphicsView::paintEvent(event);
//    QPainter p;
//    p.begin(this);

//    p.drawLine(5,5,10,10);

//    p.end();

}





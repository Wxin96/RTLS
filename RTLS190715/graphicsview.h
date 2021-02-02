#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = nullptr);
    virtual ~GraphicsView();

signals:

public slots:

private:
    void paintEvent(QPaintEvent *event);

};

#endif // GRAPHICSVIEW_H

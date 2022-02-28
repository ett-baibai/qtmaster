#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QtCharts/QChart>
#include <QtCharts\QChartView>
#include <QPointF>
#include <QList>
#include <QTimer>
#include <QWidget>
#include <QGraphicsItem>
#include <QSplineSeries>
#include <QValueAxis>
#include <QQueue>

//just include double classes, not head file
QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE   //need include this code for using chart

class paintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit paintWidget(QWidget *parent = nullptr);
    ~paintWidget();

    void mSetCanvas();
    void mDrawCoordinateAxes();
    void mInitImg();

public slots:
    void on_TimerOutToDraw();
    void on_PaintPoint(unsigned int data);

private:
    const int m_constWindowWidth;
    const int m_constWindowHeight;
    QChart * m_chart;
    QChartView *m_chartView;
    QSplineSeries *m_line; //smooth curve
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    QTimer *m_addPointTimer;
    QQueue<unsigned int> m_dataQueue;
};

#endif // PAINTWIDGET_H

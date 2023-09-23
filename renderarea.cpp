#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) :
    QWidget{parent},
    mBackgroundColor (100,100,100),
    mShape(Default),
    mPen(Qt::white),
    mPenWidth(1),
    mScale (0),
    mStepCount (0),
    mIntervalLength (0)
{
    mPen.setWidth(mPenWidth);
}
QSize RenderArea::minimumSizeHint() const
{
    return QSize(200,200);
}
QSize RenderArea::sizeHint() const
{
    return QSize(500,500);
}
void RenderArea::on_shapeChange()
{
    switch(mShape)
    {
    case Astroid:
        //mBackgroundColor = Qt::red;
        mScale = 90;
        mStepCount=250;
        mIntervalLength = 2 * M_PI;
        break;
    case Cycloid:
        mScale = 10;
        mStepCount=128;
        mIntervalLength = 4 * M_PI;
        break;
    case Huygenscycloid:
        mScale = 10;
        mStepCount=256;
        mIntervalLength = 4 * M_PI;
        break;
    case Hypocycloid:
        mScale = 40;
        mStepCount=256;
        mIntervalLength = 2 * M_PI;
        break;
    case Line:
        mScale = 100;
        mStepCount=128;
        mIntervalLength = 2;
        break;
    case Circle:
        mScale = 100;
        mStepCount=120;
        mIntervalLength = 2 * M_PI;
        break;
    case Ellipse:
        mScale = 75;
        mStepCount=256;
        mIntervalLength = 2 * M_PI;
        break;
    case Fancycurve:
        mScale = 10;
        mStepCount=512;
        mIntervalLength = 12 * M_PI;
        break;
    case Luckystarfish:
        mScale = 25;
        mStepCount=256;
        mIntervalLength = 6 * M_PI;
        break;
    case Cloud:
        mScale = 10;
        mStepCount=128;
        mIntervalLength = 28 * M_PI;
        break;
    case Invertedcloud:
        mScale = 10;
        mStepCount=128;
        mIntervalLength = 28 * M_PI;
        break;
    default:
        mScale = 0;
        mStepCount=0;
        mIntervalLength = 0;
        break;
    }
}
QPointF RenderArea::compute(float t)
{
    switch(mShape)
    {
    case Astroid:
        return compute_astroid(t);
        break;
    case Cycloid:
        return compute_cycloid(t);
        break;
    case Huygenscycloid:
        return compute_huygen_cycloid(t);
        break;
    case Hypocycloid:
        return compute_hypo_cycloid(t);
        break;
    case Line:
        return compute_line(t);
        break;
    case Circle:
        return compute_circle(t);
        break;
    case Ellipse:
        return compute_ellipse(t);
        break;
    case Fancycurve:
        return compute_fancy_curve(t);
        break;
    case Luckystarfish:
        return compute_lucky_starfish(t);
        break;
    case Cloud:
        return compute_cloud(t);
        break;
    case Invertedcloud:
        return compute_inverted_cloud(t);
        break;
    default:
        break;
    }
    return QPoint(0,0);
}
QPointF RenderArea::compute_astroid(float t)
{
    float x = pow(cos(t),3);
    float y = pow(sin(t),3);
    return QPointF (x,y);
}
QPointF RenderArea::compute_cycloid(float t)
{
    float x = 1.5 * (1 - cos(t));
    float y = 1.5 * (t - sin(t)); ;
    return QPointF (x,y);
}
QPointF RenderArea::compute_huygen_cycloid(float t)
{
    float x = 4 * (3 * cos(t) - cos(3 * t));
    float y = 4 * (3 * sin(t) - sin(3 * t)); ;
    return QPointF (x,y);
}
QPointF RenderArea::compute_hypo_cycloid(float t)
{
    float x = 1.5 * (2 * cos(t) + cos(2 * t));
    float y = 1.5 * (2 * sin(t) - sin(2 * t)); ;
    return QPointF (x,y);
}
QPointF RenderArea::compute_line(float t)
{
    float x = 1-t;
    float y = 1-t;
    return QPointF (x,y);
}
QPointF RenderArea::compute_circle(float t)
{
    float x = cos(t);
    float y = sin(t);
    return QPointF (x,y);
}
QPointF RenderArea::compute_ellipse(float t)
{
    float a = 2, b = 1.1;
    float x = a * cos(t);
    float y = b * sin(t);
    return QPointF (x,y);
}
QPointF RenderArea::compute_fancy_curve(float t)
{
    float x = 11.0f * cos(t) - 6 * cos((11.0f/6) * t);
    float y = 11.0f * sin(t) - 6 * sin((11.0f/6) * t);
    return QPointF (x,y);
}
QPointF RenderArea::compute_lucky_starfish(float t)
{
    float R = 5, r = 3, d = 5;
    float x = ( R - r) * cos(t) + d * cos(t * ((R - r)/r));
    float y = ( R - r) * sin(t) - d * sin(t * ((R - r)/r));
    return QPointF (x,y);
}
QPointF RenderArea::compute_cloud(float t)
{
    float a = 14, b = 1;
    float x = ( a + b) * cos(t * (b/a)) - b * cos(t * (( a + b)/a));
    float y = ( a + b) * sin(t * (b/a)) - b * sin(t * (( a + b)/a));
    return QPointF (x,y);
}
QPointF RenderArea::compute_inverted_cloud(float t)
{
    float a = 14, b = 1;
    float x = ( a + b) * cos(t * (b/a)) + b * cos(t * (( a + b)/a));
    float y = ( a + b) * sin(t * (b/a)) - b * sin(t * (( a + b)/a));
    return QPointF (x,y);

}
void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setBrush(mBackgroundColor);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(mPen);

    // Drawing area
    painter.drawRect(this->rect());
    QPoint center = this->rect().center();
    QPointF prevPoint = compute(0);
    QPoint prevPixel;
    prevPixel.setX(prevPoint.x() * mScale + center.x());
    prevPixel.setY(prevPoint.y() * mScale + center.y());
    //painter.drawLine(this->rect().topLeft(),this->rect().bottomRight());
    float step = mIntervalLength/mStepCount;
    float t = 0;
    QPointF point;
    QPoint pixel;
    if(mShape != Default)
    {
        while(t < mIntervalLength)
        {
            point = compute(t);
            pixel.setX(point.x() * mScale + center.x());
            pixel.setY(point.y() * mScale + center.y());

            //painter.drawPoint(pixel);
            painter.drawLine(pixel, prevPixel);
            prevPixel = pixel;
            t+=step;
        }
        point = compute(mIntervalLength);
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());

        //painter.drawPoint(pixel);
        painter.drawLine(pixel, prevPixel);
    }
}

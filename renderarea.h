#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>
#include <QPen>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    enum ShapeType
    {  Astroid,
       Cycloid,
       Huygenscycloid,
       Hypocycloid,
       Line,
       Circle,
       Ellipse,
       Fancycurve,
       Luckystarfish,
       Cloud,
       Invertedcloud,
       Default
    };

    void setBackgroundColor (QColor color) {mBackgroundColor = color;} // setter
    QColor backgroundColor () const {return mBackgroundColor;} // getter

    void setShapeColor (QColor color) {mPen.setColor(mShapeColor = color);} // setter
    QColor shapeColor () const {return mShapeColor;} // getter

    void setShape (ShapeType shape) {mShape = shape; on_shapeChange();} //setter
    ShapeType shape () const {return mShape;} // getter

    void setScale (float scale) {mScale = scale; repaint();} //setter
    float scale () const {return mScale;} // getter

    void setStepCount (float stepCount) {mStepCount = stepCount; repaint();} // setter
    float stepCount () const {return mStepCount;} // getter

    void setIntervalLength (float intervalLength) {mIntervalLength = intervalLength; repaint();} //setter
    float intervalLength () const { return mIntervalLength;} //getter

    void setPenWidth (float penWidth) { mPen.setWidth(mPenWidth = penWidth); repaint();} // setter
    int penWidth () const {return  mPenWidth;} // getter
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:

public slots:

private:
    void on_shapeChange();
    QPointF compute(float t);
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygen_cycloid(float t);
    QPointF compute_hypo_cycloid(float t);
    QPointF compute_line(float t);
    QPointF compute_circle(float t);
    QPointF compute_ellipse(float t);
    QPointF compute_fancy_curve(float t);
    QPointF compute_lucky_starfish(float t);
    QPointF compute_cloud(float t);
    QPointF compute_inverted_cloud(float t);
private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    QPen mPen;
    int mPenWidth;
    ShapeType mShape;
    int mScale;
    int mStepCount;
    float mIntervalLength;
    //float mStep = intervalLength/stepCount;

};

#endif // RENDERAREA_H

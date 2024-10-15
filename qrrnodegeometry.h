#ifndef QRRNODEGEOMETRY_H
#define QRRNODEGEOMETRY_H
#include <QSGGeometryNode>
#include <QColor>
class QRoundRectangleMaterial;
class QRRNodeGeometry:public QSGGeometryNode
{
public:
    QRRNodeGeometry();

    QColor color() const;
    void setColor(const QColor &color);

    qreal blRadius() const;
    void setBlRadius(const qreal &blRadius);

    qreal brRadius() const;
    void setBrRadius(const qreal &brRadius);

    qreal tlRadius() const;
    void setTlRadius(const qreal &tlRadius);

    qreal trRadius() const;
    void setTrRadius(const qreal &trRadius);

    QRoundRectangleMaterial *getRRMaterial();
    void updateGeometry();

    qreal getWidth() const;
    void setWidth(const qreal &width);

    qreal getHeight() const;
    void setHeight(const qreal &height);



    QSGGeometry::AttributeSet setAttribute();

//    QVector2D getResolution() const;
//    void setResolution(const QVector2D &resolution);

private:
    QColor m_color;
    qreal m_blRadius;
    qreal m_brRadius;
    qreal m_tlRadius;
    qreal m_trRadius;
    qreal m_width;
    qreal m_height;
};

#endif // QRRNODEGEOMETRY_H

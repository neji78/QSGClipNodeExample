#ifndef QROUNDRECTANGLEMATERIAL_H
#define QROUNDRECTANGLEMATERIAL_H

#include <QSGMaterial>
class QRoundRectangleMaterial : public QSGMaterial
{
public:
    QRoundRectangleMaterial();

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

    QSGMaterialType *type() const override;
    int compare(const QSGMaterial *other) const override;

    QSGMaterialShader *createShader() const override;

    QVector2D resolution() const;
    void setResolution(const QVector2D &resolution);

private:
    QColor m_color;
    qreal m_blRadius;
    qreal m_brRadius;
    qreal m_tlRadius;
    qreal m_trRadius;
    QVector2D m_resolution;
};

#endif // QROUNDRECTANGLEMATERIAL_H

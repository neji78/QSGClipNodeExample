#include "qroundrectanglematerial.h"
#include "qroundedrectanglematerialshader.h"

QRoundRectangleMaterial::QRoundRectangleMaterial():QSGMaterial(),
    m_color(QColor("white")),
    m_blRadius(0.0f),
    m_brRadius(0.0f),
    m_tlRadius(0.0f),
    m_trRadius(0.0f)
{

}

QColor QRoundRectangleMaterial::color() const
{
    return m_color;
}

void QRoundRectangleMaterial::setColor(const QColor &color)
{
    m_color = color;
}

qreal QRoundRectangleMaterial::blRadius() const
{
    return m_blRadius;
}

void QRoundRectangleMaterial::setBlRadius(const qreal &blRadius)
{
    m_blRadius = blRadius;
}

qreal QRoundRectangleMaterial::brRadius() const
{
    return m_brRadius;
}

void QRoundRectangleMaterial::setBrRadius(const qreal &brRadius)
{
    m_brRadius = brRadius;
}

qreal QRoundRectangleMaterial::tlRadius() const
{
    return m_tlRadius;
}

void QRoundRectangleMaterial::setTlRadius(const qreal &tlRadius)
{
    m_tlRadius = tlRadius;
}

qreal QRoundRectangleMaterial::trRadius() const
{
    return m_trRadius;
}

void QRoundRectangleMaterial::setTrRadius(const qreal &trRadius)
{
    m_trRadius = trRadius;
}

QSGMaterialType *QRoundRectangleMaterial::type() const
{
    static QSGMaterialType type;
    return &type;
}

int QRoundRectangleMaterial::compare(const QSGMaterial *other) const
{
    Q_UNUSED(other)
//    qDebug()<<__LINE__<<__PRETTY_FUNCTION__<<static_cast<const QRoundRectangleMaterial *>(other)->blRadius();
//    auto other_ = static_cast<const QRoundRectangleMaterial *>(other);

//    if (this->shaderProgramId < other_->shaderProgramId) {
//        return -1;
//    } else if (this->shaderProgramId > other_->shaderProgramId) {
//        return 1;
//    }

    return 0;
}

QSGMaterialShader *QRoundRectangleMaterial::createShader() const
{
    return new QRoundedRectangleMaterialShader();
}

QVector2D QRoundRectangleMaterial::resolution() const
{
    return m_resolution;
}

void QRoundRectangleMaterial::setResolution(const QVector2D &resolution)
{
    m_resolution = resolution;
}

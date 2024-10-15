#include "qrrnodegeometry.h"
#include "qroundrectanglematerial.h"
#include "objectUtility.h"
#include <QDebug>
QRRNodeGeometry::QRRNodeGeometry():
    m_width(0.0f),
    m_height(0.0f)
{
    static QSGGeometry::Attribute attributes[2];
    static QSGGeometry::AttributeSet attributeSet;

    attributes[0] = QSGGeometry::Attribute::create(0, 2, GL_FLOAT, true);
    attributes[1] = QSGGeometry::Attribute::create(1, 2, GL_FLOAT, false);

    attributeSet.count = 2;
    attributeSet.stride = sizeof( Shape::Vertex4D );
    attributeSet.attributes = attributes;
    auto geometry = new QSGGeometry( attributeSet/*setAttribute()*/, 4, 6 );
    geometry->setDrawingMode( QSGGeometry::DrawTriangles );
    setGeometry( geometry );
    setFlag( QSGGeometryNode::OwnsGeometry, true );

    auto material = new QRoundRectangleMaterial();
    material->setFlag( QSGMaterial::Blending );
    setMaterial( material );
    setFlag( QSGGeometryNode::OwnsMaterial, true );
    qDebug()<<__LINE__<<__PRETTY_FUNCTION__;

}

QColor QRRNodeGeometry::color() const
{
    return m_color;
}

void QRRNodeGeometry::setColor(const QColor &color)
{
    if(m_color == color)
        return;
    m_color = color;
    getRRMaterial()->setColor(m_color);
    markDirty(DirtyMaterial);
}

qreal QRRNodeGeometry::blRadius() const
{
    return m_blRadius;
}

void QRRNodeGeometry::setBlRadius(const qreal &blRadius)
{
    if(m_blRadius == blRadius)
        return;
    m_blRadius = blRadius;
    getRRMaterial()->setBlRadius(m_blRadius);
    markDirty(DirtyMaterial);
}

qreal QRRNodeGeometry::brRadius() const
{
    return m_brRadius;
}

void QRRNodeGeometry::setBrRadius(const qreal &brRadius)
{
    if(m_brRadius == brRadius)
        return;
    m_brRadius = brRadius;
    getRRMaterial()->setBrRadius(m_brRadius);
    markDirty(DirtyMaterial);
}

qreal QRRNodeGeometry::tlRadius() const
{
    return m_tlRadius;
}

void QRRNodeGeometry::setTlRadius(const qreal &tlRadius)
{
    if(m_tlRadius == tlRadius)
        return;
    m_tlRadius = tlRadius;
    getRRMaterial()->setTlRadius(m_tlRadius);
    markDirty(DirtyMaterial);
}

qreal QRRNodeGeometry::trRadius() const
{
    return m_trRadius;
}

void QRRNodeGeometry::setTrRadius(const qreal &trRadius)
{
    if(m_trRadius == trRadius)
        return;
    m_trRadius = trRadius;
    getRRMaterial()->setTrRadius(m_trRadius);
    markDirty(DirtyMaterial);
}

QRoundRectangleMaterial *QRRNodeGeometry::getRRMaterial()
{
    return static_cast<QRoundRectangleMaterial *>(material());
}

void QRRNodeGeometry::updateGeometry()
{
    auto indices = geometry()->indexDataAsUShort();
    auto vertices = reinterpret_cast<Shape::Vertex4D *>(geometry()->vertexData());
    int vertI = 0;
    int quadI = 0;
    QPointF tl(0,0);
    QPointF tr(0,getWidth());
    QPointF bl(getHeight(),0);
    QPointF br(getWidth(),getHeight()*2);
    QRectF rectI = QRectF( 0, 0, getWidth(), getHeight() );
    auto unitRect = QRectF(0.0,0.0,1.0,1.0);
    QPointF utl(0,0);
    QPointF utr(0,0.5);
    QPointF ubl(0.5,0);
    QPointF ubr(0.5,1.0);
    qDebug()<<__LINE__<<__PRETTY_FUNCTION__<<rectI<<geometry()->indexCount();
    for( int i = 0; i < geometry()->indexCount(); i += 6 )
    {
        indices[ i + 0 ] = static_cast<quint16>(vertI + 0);
        indices[ i + 1 ] = static_cast<quint16>(vertI + 1);
        indices[ i + 2 ] = static_cast<quint16>(vertI + 2);
        indices[ i + 3 ] = static_cast<quint16>(vertI + 2);
        indices[ i + 4 ] = static_cast<quint16>(vertI + 3);
        indices[ i + 5 ] = static_cast<quint16>(vertI + 0);

        vertices[ vertI + 0 ].set( static_cast<float>(bl.x()),
                                static_cast<float>(bl.y()),
                                ubl.x(),
                                ubl.y());

        vertices[ vertI + 1 ].set( static_cast<float>(br.x()),
                                static_cast<float>(br.y()),
                                ubr.x(),
                                ubr.y());

        vertices[ vertI + 2 ].set( static_cast<float>(tr.x()),
                                static_cast<float>(tr.y()),
                                utr.x(),
                                utr.y());

        vertices[ vertI + 3 ].set( static_cast<float>(tl.x()),
                                static_cast<float>(tl.y()),
                                utl.x(),
                                utl.y());

        vertI += 4;
        ++quadI;
    }
    markDirty(DirtyGeometry);
    getRRMaterial()->setResolution(QVector2D(getWidth(),getHeight()));
    markDirty(DirtyMaterial);

}

qreal QRRNodeGeometry::getWidth() const
{
    return m_width;
}

void QRRNodeGeometry::setWidth(const qreal &width)
{
    if(m_width == width)
        return;
    m_width = width;
    updateGeometry();
}

qreal QRRNodeGeometry::getHeight() const
{
    return m_height;
}

void QRRNodeGeometry::setHeight(const qreal &height)
{
    if(m_height == height)
        return;
    m_height = height;
    updateGeometry();
}


QSGGeometry::AttributeSet QRRNodeGeometry::setAttribute()
{
    static QSGGeometry::Attribute attributes[2];
    static QSGGeometry::AttributeSet attributeSet;

    attributes[0] = QSGGeometry::Attribute::create(0, 2, GL_FLOAT, true);
    attributes[1] = QSGGeometry::Attribute::create(1, 2, GL_FLOAT, false);

    attributeSet.count = 2;
    attributeSet.stride = sizeof( Shape::Vertex4D );
    attributeSet.attributes = attributes;
    return attributeSet;
}


//void QRRNodeGeometry::setResolution(const QVector2D &resolution)
//{
//    if(m_resolution == resolution)
//        return;
//    m_resolution = resolution;
//    getRRMaterial()->setResolution(m_resolution);
//    markDirty(DirtyMaterial);
//}

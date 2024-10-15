#include "qroundedrectangleclipnode.h"
#include "objectUtility.h"
QRoundedRectangleClipNode::QRoundedRectangleClipNode()
{
//    static QSGGeometry::Attribute attributes[2];
//    static QSGGeometry::AttributeSet attributeSet;

//    attributes[0] = QSGGeometry::Attribute::create(0, 2, GL_FLOAT, true);
//    attributes[1] = QSGGeometry::Attribute::create(1, 2, GL_FLOAT, false);

//    attributeSet.count = 2;
//    attributeSet.stride = sizeof( Shape::Vertex4D );
//    attributeSet.attributes = attributes;
//    auto geometry = new QSGGeometry( attributeSet/*setAttribute()*/, 4, 6 );
//    geometry->setDrawingMode( QSGGeometry::DrawTriangles );
//    setGeometry( geometry );
//    setFlag( QSGGeometryNode::OwnsGeometry, true );

    qDebug()<<__LINE__<<__PRETTY_FUNCTION__;
}

void QRoundedRectangleClipNode::updateGeometry()
{
//    auto indices = geometry()->indexDataAsUShort();
//    auto vertices = reinterpret_cast<Shape::Vertex4D *>(geometry()->vertexData());
//    int vertI = 0;
//    int quadI = 0;
//    QPointF tl(0,0);
//    QPointF tr(0,width());
//    QPointF bl(height(),0);
//    QPointF br(width(),height()*2);
//    QRectF rectI = QRectF( 0, 0, width(), height() );
//    auto unitRect = QRectF(0.0,0.0,1.0,1.0);
//    QPointF utl(0,0);
//    QPointF utr(0,0.5);
//    QPointF ubl(0.5,0);
//    QPointF ubr(0.5,1.0);
//    qDebug()<<__LINE__<<__PRETTY_FUNCTION__<<rectI<<geometry()->indexCount();
//    for( int i = 0; i < geometry()->indexCount(); i += 6 )
//    {
//        indices[ i + 0 ] = static_cast<quint16>(vertI + 0);
//        indices[ i + 1 ] = static_cast<quint16>(vertI + 1);
//        indices[ i + 2 ] = static_cast<quint16>(vertI + 2);
//        indices[ i + 3 ] = static_cast<quint16>(vertI + 2);
//        indices[ i + 4 ] = static_cast<quint16>(vertI + 3);
//        indices[ i + 5 ] = static_cast<quint16>(vertI + 0);

//        vertices[ vertI + 0 ].set( static_cast<float>(bl.x()),
//                                static_cast<float>(bl.y()),
//                                ubl.x(),
//                                ubl.y());

//        vertices[ vertI + 1 ].set( static_cast<float>(br.x()),
//                                static_cast<float>(br.y()),
//                                ubr.x(),
//                                ubr.y());

//        vertices[ vertI + 2 ].set( static_cast<float>(tr.x()),
//                                static_cast<float>(tr.y()),
//                                utr.x(),
//                                utr.y());

//        vertices[ vertI + 3 ].set( static_cast<float>(tl.x()),
//                                static_cast<float>(tl.y()),
//                                utl.x(),
//                                utl.y());

//        vertI += 4;
//        ++quadI;
//    }
//    markDirty(DirtyGeometry);
}

qreal QRoundedRectangleClipNode::width() const
{
    return m_width;
}

void QRoundedRectangleClipNode::setWidth(const qreal &width)
{
    if(m_width == width)
        return;
    m_width = width;
//    updateGeometry();
}

qreal QRoundedRectangleClipNode::height() const
{
    return m_height;
}

void QRoundedRectangleClipNode::setHeight(const qreal &height)
{
    if(m_height == height)
        return;
    m_height = height;
//    updateGeometry();
}

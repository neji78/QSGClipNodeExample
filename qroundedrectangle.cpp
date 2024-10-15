#include "qroundedrectangle.h"
#include "qrrnodegeometry.h"
#include "objectUtility.h"
#include "qroundedrectangleclipnode.h"
QRoundedRectangle::QRoundedRectangle(QQuickItem *parent): QQuickItem(parent)
{

    setFlag(ItemHasContents,true);
//    setFlag(ItemClipsChildrenToShape,true);
//    connect(this,&QQuickItem::widthChanged,this,&QQuickItem::update);
//    connect(this,&QQuickItem::heightChanged,this,&QQuickItem::update);
}

void QRoundedRectangle::registerType()
{
    qmlRegisterType<QRoundedRectangle>("component.shape",1,0,"RoundedRectangle");
}
QSGNode *QRoundedRectangle::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *paintNodeData)
{

    Q_UNUSED( paintNodeData );
//    QRoundedRectangleClipNode *clipNode = nullptr;
    QSGClipNode *clipNode = nullptr;
    QRRNodeGeometry* geometryNode = nullptr;
    if( oldNode )
    {
        clipNode = static_cast<QSGClipNode *>( oldNode );
        geometryNode = static_cast<QRRNodeGeometry *>( clipNode->firstChild() );
    }else
    {
        clipNode = new QSGClipNode();
        clipNode->setIsRectangular(false);
//        clipNode->setClipRect(QRectF(0.0,0.0,40,40));
        geometryNode = new QRRNodeGeometry();
        clipNode->setGeometry(geometryNode->geometry());
        clipNode->appendChildNode(geometryNode);
//        clipNode->markDirty(QSGNode::DirtyNodeAdded);

        qDebug()<<__LINE__<<__PRETTY_FUNCTION__<<clipNode->type()<<clipNode->isRectangular()<<clipNode->childCount();
    }
//    clipNode->setWidth(width());
//    clipNode->setHeight(height());
    geometryNode->setWidth(width());
    geometryNode->setHeight(height());
    geometryNode->setColor(color());
    geometryNode->setBlRadius(normalizeRadius(blRadius()));
    geometryNode->setBrRadius(normalizeRadius(brRadius()));
    geometryNode->setTlRadius(normalizeRadius(tlRadius()));
    geometryNode->setTrRadius(normalizeRadius(trRadius()));
    clipNode->markDirty(QSGNode::DirtyGeometry);
    return clipNode;
}
qreal QRoundedRectangle::blRadius() const
{
    return m_blRadius;
}

qreal QRoundedRectangle::brRadius() const
{
    return m_brRadius;
}

qreal QRoundedRectangle::tlRadius() const
{
    return m_tlRadius;
}

qreal QRoundedRectangle::trRadius() const
{
    return m_trRadius;
}

QColor QRoundedRectangle::color() const
{
    return m_color;
}

void QRoundedRectangle::setBlRadius(qreal blRadius)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_blRadius, blRadius))
        return;

    m_blRadius = blRadius;
    update();
    emit blRadiusChanged(m_blRadius);
}

void QRoundedRectangle::setTlRadius(qreal tlRadius)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_tlRadius, tlRadius))
        return;

    m_tlRadius = tlRadius;
    update();
    emit tlRadiusChanged(m_tlRadius);
}

void QRoundedRectangle::setTrRadius(qreal trRadius)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_trRadius, trRadius))
        return;

    m_trRadius = trRadius;
    update();
    emit trRadiusChanged(m_trRadius);
}
qreal QRoundedRectangle::normalizeRadius(const qreal &radius)
{
    return radius;
    if(radius == 0)
        return radius;
    qreal min;
    qreal result;
    if(height() > 0 ){
        if(width() > 0){
            min = qMin(height()/2,width()/2);
        }else{
            min = height()/2;
        }
    }else{
        if(width() > 0){
            min = width()/2;
        }else{
            min = radius;
        }
    }

    qDebug()<<__LINE__<<__PRETTY_FUNCTION__<<radius<<min<<height()<<width();
    result = qMin(radius/min,0.5);
    return result;

}
void QRoundedRectangle::setColor(QColor color)
{
    if (m_color == color)
        return;

    m_color = color;
    update();
    emit colorChanged(m_color);
}

void QRoundedRectangle::setBrRadius(qreal brRadius)
{
    if (m_brRadius == brRadius)
        return;

    m_brRadius = brRadius;
    update();
    emit brRadiusChanged(m_brRadius);
}

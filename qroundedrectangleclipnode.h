#ifndef QROUNDEDRECTANGLECLIPNODE_H
#define QROUNDEDRECTANGLECLIPNODE_H
#include <QSGClipNode>

class QRoundedRectangleClipNode:public QSGClipNode
{
public:
    QRoundedRectangleClipNode();

    void updateGeometry();
    qreal width() const;
    void setWidth(const qreal &width);

    qreal height() const;
    void setHeight(const qreal &height);

private:
    qreal m_width;
    qreal m_height;
};

#endif // QROUNDEDRECTANGLECLIPNODE_H

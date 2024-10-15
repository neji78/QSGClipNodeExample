#ifndef QROUNDEDRECTANGLE_H
#define QROUNDEDRECTANGLE_H

#include <QQuickItem>

class QRoundedRectangle : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(qreal blRadius READ blRadius WRITE setBlRadius NOTIFY blRadiusChanged)
    Q_PROPERTY(qreal brRadius READ brRadius WRITE setBrRadius NOTIFY brRadiusChanged)
    Q_PROPERTY(qreal tlRadius READ tlRadius WRITE setTlRadius NOTIFY tlRadiusChanged)
    Q_PROPERTY(qreal trRadius READ trRadius WRITE setTrRadius NOTIFY trRadiusChanged)

public:
    QRoundedRectangle(QQuickItem *parent = nullptr);
    static void registerType();
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *) Q_DECL_OVERRIDE;
    qreal blRadius() const;
    qreal brRadius() const;
    qreal tlRadius() const;
    qreal trRadius() const;
    QColor color() const;
    qreal normalizeRadius(const qreal &radius);

public slots:
    void setBlRadius(qreal blRadius);
    void setBrRadius(qreal brRadius);
    void setTlRadius(qreal tlRadius);
    void setTrRadius(qreal trRadius);
    void setColor(QColor color);

signals:

    void blRadiusChanged(qreal blRadius);
    void brRadiusChanged(qreal brRadius);
    void tlRadiusChanged(qreal tlRadius);
    void trRadiusChanged(qreal trRadius);
    void colorChanged(QColor color);

private:
    qreal m_blRadius;
    qreal m_brRadius;
    qreal m_colorChanged;
    qreal m_tlRadius;
    qreal m_trRadius;
    QColor m_color;
};

#endif // QROUNDEDRECTANGLE_H

#ifndef OBJECTUTILITY_H
#define OBJECTUTILITY_H
#include <QDebug>
namespace Shape {
struct Vertex4D
{
    float X;
    float Y;
    float U;
    float V;

    void set(float x, float y, float u, float v )
    {
        X = x;
        Y = y;
        U = u;
        V = v;
        qDebug()<<"Vertex4D set: "<< x<< y<< u<<v;
    }
};
}
#endif // OBJECTUTILITY_H

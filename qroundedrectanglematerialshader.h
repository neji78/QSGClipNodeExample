#ifndef QROUNDEDRECTANGLEMATERIALSHADER_H
#define QROUNDEDRECTANGLEMATERIALSHADER_H
#include <QSGMaterialShader>

class QRoundedRectangleMaterialShader:public QSGMaterialShader
{
public:
    QRoundedRectangleMaterialShader();
//    const char *vertexShader() const;
//    const char *fragmentShader() const;
    char const *const *attributeNames() const;
    void initialize();
    void updateState(const RenderState &state, QSGMaterial *newMaterial, QSGMaterial *oldMaterial);
private:
    int m_id_matrix;
    int m_id_resolution;
    int m_id_color;
    int m_id_blradius;
    int m_id_brradius;
    int m_id_tlradius;
    int m_id_trradius;
    int m_id_opacity;
};

#endif // QROUNDEDRECTANGLEMATERIALSHADER_H

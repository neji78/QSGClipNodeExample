#include "qroundedrectanglematerialshader.h"
#include "qroundrectanglematerial.h"
#include <QOpenGLContext>
QRoundedRectangleMaterialShader::QRoundedRectangleMaterialShader():QSGMaterialShader(),
    m_id_matrix(-1)
{

}

//const char *QRoundedRectangleMaterialShader::vertexShader() const
//{
//    return "attribute highp vec4 aVertex;\n"
//           "attribute highp vec2 qt_TexCoord0;\n"
//           "uniform highp mat4 uMatrix;\n"
//           "uniform highp vec2 uResolution;\n"
//           "varying highp vec2 coord;\n"
//           "void main()\n"
//           "{\n"
//           "gl_Position =  uMatrix*aVertex;\n"
//           "coord = qt_TexCoord0*uResolution;\n"
//           "}";
//}

/*const char *QRoundedRectangleMaterialShader::fragmentShader() const
{
    return
    "uniform lowp float uBLradius;\n"
    "uniform lowp float uBRradius;\n"
    "uniform lowp float uTLradius;\n"
    "uniform lowp float uTRradius;\n"
    "uniform lowp vec3  uColor;\n"
    "uniform lowp float uOpacity;\n"
    "varying highp vec2 coord;\n"
    "lowp float rectangle(vec2 coord,vec4 rect)\n"
    "{\n"
        "lowp float x1 = step(rect.x,coord.x);\n"
        "lowp float y1 = step(rect.y,coord.y);\n"
        "lowp float w1 = 1.0 - step((rect.z),coord.x);\n"
        "lowp float h1 = 1.0 - step((rect.w),coord.y);\n"
        "return x1*y1*w1*h1;\n"

"}\n"
    "lowp vec4 getCornerRect(in vec2 corner,lowp float _radius,int cr)\n"
    "{\n"
    "if(cr == 0){//BL\n"
    "return vec4(corner.x,corner.y,corner.x + _radius,corner.y + _radius);\n"
    "}else if(cr == 1){//TL\n"
    "return vec4(corner.x,corner.y - _radius,corner.x + _radius,corner.y);\n"
    "}else if(cr == 2){//TR\n"
    "return vec4(corner.x - _radius,corner.y - _radius,corner.x ,corner.y);\n"
    "}else{//BR\n"
    "return vec4(corner.x - _radius,corner.y,corner.x ,corner.y + _radius);\n"
    "}\n"

    "}\n"
    "lowp float pickCornerRectangle(in vec2 coord, in lowp float _radius, in vec2 corner,int cr)\n"
    "{\n"
    "return 1.-rectangle(coord,getCornerRect(corner,_radius,cr));\n"
    "}\n"
    "lowp vec2 getLimit(in vec2 coord,in vec2 center, int cr)\n"
    "{\n"
    "if(cr == 0){//BL\n"
    "return vec2((1.-step(center.x,coord.x)),(1.-step(center.y,coord.y)));\n"
    "}else if(cr == 1){//TL\n"
    "return vec2((1.-step(center.x,coord.x)),(step(center.y,coord.y)));\n"
    "}else if(cr == 2){//TR\n"
    "return vec2((step(center.x,coord.x)),(step(center.y,coord.y)));\n"
    "}else{//BR\n"
    "return vec2((step(center.x,coord.x)),(1.-step(center.y,coord.y)));\n"
    "}\n"

    "}\n"
    "lowp vec2 getCorner(vec4 rect, int cr)\n"
    "{\n"
    "if(cr == 0){//BL\n"
    "return vec2(rect.x,rect.y);\n"
    "}else if(cr == 1){//TL\n"
    "return vec2(rect.x,rect.w);\n"
    "}else if(cr == 2){//TR\n"
    "return vec2(rect.z,rect.w);\n"
    "}else{//BR\n"
    "return vec2(rect.z,rect.y);\n"
    "}\n"
    "}\n"
    "lowp vec2 getCenter(in vec2 corner, in lowp float _radius,int cr)\n"
    "{\n"
    "if(cr == 0){//BL\n"
    "return corner + vec2(_radius) ;\n"
    "}else if(cr == 1){//TL\n"
    "return corner + vec2(_radius,-_radius) ;\n"
    "}else if(cr == 2){//TR\n"
    "return corner - vec2(_radius) ;\n"
    "}else{//BR\n"
    "return corner + vec2(-_radius,_radius) ;\n"
    "}\n"
    "}\n"
    "lowp float roundCorner(in vec2 _st, in lowp float _radius, in vec2 corner, int cr){\n"
    "lowp vec2 center = getCenter(corner,_radius,cr) ;\n"
    "lowp vec2 dist = _st-center;\n"
    "lowp float circle = 1.-smoothstep(_radius-(_radius*0.01),"
    "                                   _radius+(_radius*0.01),"
    "                                   sqrt(dot(dist,dist))*1.0);\n"
    "lowp vec2 limit = getLimit(_st,center,cr);\n"
    "return circle*limit.x*limit.y;\n"
    "}\n"
    "void main()\n"
    "{\n"

    "lowp float height = 300.0;\n"
    "lowp float x0 = 100.0;\n"
    //        "lowp float aspect = 1.0/*sqrt(dot(iResolution.xy,iResolution.xy));\n"
    //        "lowp vec2 coord = vec2(coord.x/aspect,coord.y/aspect);\n"
    //        "lowp vec4 rect = vec4(x0/aspect,20.0/aspect,(height + x0)/aspect,(height+20.)/aspect);\n"
    //        "lowp vec3 uv = vec3(1.0,0.0,0.0);\n"
    //        "lowp float radius = 0.1;\n"
    //        "lowp float rectShape = rectangle(coord,rect);\n"
    //    uv = uv*rectShape;\n"
    //    if(uBLradius > 0.){
    //        int cr = 0;\n"
    //        lowp vec2 corner_ = getCorner(rect,cr);\n"
    //        lowp float pick = pickCornerRectangle(coord,radius,corner_,cr);\n"
    //        lowp float roundside = roundCorner(coord,radius,corner_,cr);\n"
    //        uv = uv*(pick+roundside);\n"
    //    }
    //        "gl_FragColor = vec4(uColor,1.0);\n"
    //        "}\n";

    //}*/

    //const char *QRoundedRectangleMaterialShader::fragmentShader() const
    //{

    //}

    const char * const *QRoundedRectangleMaterialShader::attributeNames() const
{
    static char const *const names[] = { "aVertex","qt_TexCoord0",0};
    return names;
}

void QRoundedRectangleMaterialShader::initialize()
{

    //    QOpenGLContext* context = QOpenGLContext::currentContext();
    //    if (context) {
    //        qDebug() << "OpenGL Version:" << context->format().majorVersion() << "." << context->format().minorVersion();
    //        qDebug() << "Profile:" << (context->format().profile() == QSurfaceFormat::CoreProfile ? "Core" : "Compatibility");
    //        qDebug() << "Vendor:" << reinterpret_cast<const char*>(glGetString(GL_VENDOR));
    //        qDebug() << "Renderer:" << reinterpret_cast<const char*>(glGetString(GL_RENDERER));
    //        qDebug() << "GLSL Version:" << reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION));
    //    } else {
    //        qDebug() << "No current OpenGL context available.";
    //    }
    QSGMaterialShader::initialize();

    // Compile the shader
    bool vertResult = program()->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shape/shader/roundedRectangle.vert");
    bool fragResult = program()->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shape/shader/roundedRectangle.frag");

    program()->link();
    m_id_matrix = program()->uniformLocation("uMatrix");
    m_id_resolution = program()->uniformLocation("uResolution");
    m_id_color = program()->uniformLocation("uColor");
    m_id_blradius = program()->uniformLocation("uBLradius");
    m_id_brradius = program()->uniformLocation("uBRradius");
    m_id_tlradius = program()->uniformLocation("uTLradius");
    m_id_trradius = program()->uniformLocation("uTRradius");
    m_id_opacity = program()->uniformLocation("uOpacity");


    qDebug()<<__LINE__<<__PRETTY_FUNCTION__<<program()->log()<<vertResult<<fragResult;
}

void QRoundedRectangleMaterialShader::updateState(const QSGMaterialShader::RenderState &state, QSGMaterial *newMaterial, QSGMaterial *oldMaterial)
{
    qDebug()<<__LINE__<<__PRETTY_FUNCTION__;
    if (state.isMatrixDirty()){
        program()->setUniformValue(m_id_matrix, state.combinedMatrix());
    }
    if (state.isOpacityDirty()){
        qDebug()<<__LINE__<<__PRETTY_FUNCTION__<<state.opacity();
        program()->setUniformValue(m_id_opacity, state.opacity() );
    }
    if(newMaterial != oldMaterial){
        auto material = static_cast<QRoundRectangleMaterial *>(newMaterial);
        //update uniform data
        auto color = QVector3D(material->color().redF(),material->color().greenF(),material->color().blueF());
        qDebug()<<__LINE__<<__PRETTY_FUNCTION__<<color;
        program()->setUniformValue(m_id_resolution, material->resolution() );
        program()->setUniformValue(m_id_color,color);
        program()->setUniformValue(m_id_blradius,static_cast<GLfloat>(material->blRadius()));
        program()->setUniformValue(m_id_brradius,static_cast<GLfloat>(material->brRadius()));
        program()->setUniformValue(m_id_tlradius,static_cast<GLfloat>(material->tlRadius()));
        program()->setUniformValue(m_id_trradius,static_cast<GLfloat>(material->trRadius()));
    }
}

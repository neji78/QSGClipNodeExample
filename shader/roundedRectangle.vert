attribute highp vec4 aVertex;
attribute highp vec2 qt_TexCoord0;
uniform highp mat4 uMatrix;
uniform highp vec2 uResolution;
varying highp vec2 coord;
void main()
{
    gl_Position =  uMatrix*aVertex;
    coord = qt_TexCoord0*uResolution;
}

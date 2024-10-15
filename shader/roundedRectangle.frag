uniform lowp float uBLradius;
uniform lowp float uBRradius;
uniform lowp float uTLradius;
uniform lowp float uTRradius;
uniform lowp vec3  uColor;
uniform lowp float uOpacity;
varying highp vec2 coord;
uniform highp vec2 uResolution;
lowp float rectangle(vec2 coord,vec4 rect)
{
    lowp float x1 = step(rect.x,coord.x);
    lowp float y1 = step(rect.y,coord.y);
    lowp float w1 = 1.0 - step((rect.z),coord.x);
    lowp float h1 = 1.0 - step((rect.w),coord.y);
    return x1*y1*w1*h1;

}
lowp vec4 getCornerRect(in vec2 corner,lowp float _radius,int cr)
{
    if(cr == 0){//BL
        return vec4(corner.x,corner.y,corner.x + _radius,corner.y + _radius);
    }else if(cr == 1){//TL
        return vec4(corner.x,corner.y - _radius,corner.x + _radius,corner.y);
    }else if(cr == 2){//TR
        return vec4(corner.x - _radius,corner.y - _radius,corner.x ,corner.y);
    }else{//BR
        return vec4(corner.x - _radius,corner.y,corner.x ,corner.y + _radius);
    }
    
}
lowp float pickCornerRectangle(in vec2 coord, in lowp float _radius, in vec2 corner,int cr)
{
    return 1.0-rectangle(coord,getCornerRect(corner,_radius,cr));
}
lowp vec2 getLimit(in vec2 coord,in vec2 center, int cr)
{
    if(cr == 0){//BL
        return vec2((1.-step(center.x,coord.x)),(1.-step(center.y,coord.y)));
    }else if(cr == 1){//TL
        return vec2((1.-step(center.x,coord.x)),(step(center.y,coord.y)));
    }else if(cr == 2){//TR
        return vec2((step(center.x,coord.x)),(step(center.y,coord.y)));
    }else{//BR
        return vec2((step(center.x,coord.x)),(1.-step(center.y,coord.y)));
    }
    
}
lowp vec2 getCorner(vec4 rect, int cr)
{
    if(cr == 0){//BL
        return vec2(rect.x,rect.y);
    }else if(cr == 1){//TL
        return vec2(rect.x,rect.w);
    }else if(cr == 2){//TR
        return vec2(rect.z,rect.w);
    }else{//BR
        return vec2(rect.z,rect.y);
    }
}
lowp vec2 getCenter(in vec2 corner, in lowp float _radius,int cr)
{
    if(cr == 0){//BL
        return corner + vec2(_radius) ;
    }else if(cr == 1){//TL
        return corner + vec2(_radius,-_radius) ;
    }else if(cr == 2){//TR
        return corner - vec2(_radius) ;
    }else{//BR
        return corner + vec2(-_radius,_radius) ;
    }
}
lowp float roundCorner(in vec2 _st, in lowp float _radius, in vec2 corner, int cr){
    lowp vec2 center = getCenter(corner,_radius,cr) ;
    lowp vec2 dist = _st-center;
    lowp float circle = 1.-smoothstep(_radius-(_radius*0.01),
                                 _radius+(_radius*0.01),
                                 sqrt(dot(dist,dist))*1.0);
    lowp vec2 limit = getLimit(_st,center,cr);
    return circle*limit.x*limit.y;
}
void main()
{

    lowp vec4 rect = vec4(0.0,0.0,uResolution.x,uResolution.y);
    lowp vec3 uv = uColor;
    lowp float opacity = uOpacity;
//    if(uBLradius > 0.){
//        int cr = 1;
//        lowp vec2 corner_ = getCorner(rect,cr);
//        lowp float pick = pickCornerRectangle(coord,uBLradius,corner_,cr);
//        lowp float roundside = roundCorner(coord,uBLradius,corner_,cr);
//        opacity = opacity*(pick + roundside);
//    }
    gl_FragColor =vec4(uColor,opacity);
}

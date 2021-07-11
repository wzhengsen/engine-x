#include "CCLuaConvertSol.hpp"
using namespace cocos2d;

// Convert cocos2d::Vec2
int sol_lua_push(sol::types<cocos2d::Vec2>, lua_State* L, const cocos2d::Vec2& val) {
    lua_createtable(L, 0, 2);
    sol::stack::raw_set_field(L, "x", val.x);
    sol::stack::raw_set_field(L, "y", val.y);
    return 1;
}
cocos2d::Vec2 sol_lua_get(sol::types<cocos2d::Vec2>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    float x = t["x"];float y = t["y"];
    tracking.use(1);
    return { x,y };
}

// Convert cocos2d::Vec3
int sol_lua_push(sol::types<cocos2d::Vec3>, lua_State* L, const cocos2d::Vec3& val) {
    lua_createtable(L, 0, 3);
    sol::stack::raw_set_field(L, "x", val.x);
    sol::stack::raw_set_field(L, "y", val.y);
    sol::stack::raw_set_field(L, "z", val.z);
    return 1;
}
cocos2d::Vec3 sol_lua_get(sol::types<cocos2d::Vec3>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    float x = t["x"];float y = t["y"];float z = t["z"];
    tracking.use(1);
    return { x,y,z };
}

// Convert cocos2d::Vec4
int sol_lua_push(sol::types<cocos2d::Vec4>, lua_State* L, const cocos2d::Vec4& val) {
    lua_createtable(L, 0, 4);
    sol::stack::raw_set_field(L, "x", val.x);
    sol::stack::raw_set_field(L, "y", val.y);
    sol::stack::raw_set_field(L, "z", val.z);
    sol::stack::raw_set_field(L, "w", val.w);
    return 1;
}
cocos2d::Vec4 sol_lua_get(sol::types<cocos2d::Vec4>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    float x = t["x"];float y = t["y"];float z = t["z"];
    float w = t["w"];
    tracking.use(1);
    return { x,y,z,w };
}

// Convert cocos2d::BlendFunc
int sol_lua_push(sol::types<cocos2d::BlendFunc>, lua_State* L, const cocos2d::BlendFunc& val) {
    lua_createtable(L, 0, 2);
    sol::stack::raw_set_field(L, "src", val.src);
    sol::stack::raw_set_field(L, "dst", val.dst);
    return 1;
}
cocos2d::BlendFunc sol_lua_get(sol::types<cocos2d::BlendFunc>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    backend::BlendFactor src = t["src"];
    backend::BlendFactor dst = t["dst"];
    tracking.use(1);
    return { src,dst };
}

#if CC_USE_PHYSICS
// Convert cocos2d::PhysicsMaterial
int sol_lua_push(sol::types<cocos2d::PhysicsMaterial>, lua_State* L, const cocos2d::PhysicsMaterial& val) {
    lua_createtable(L, 0, 3);
    sol::stack::raw_set_field(L, "density", val.density);
    sol::stack::raw_set_field(L, "restitution", val.restitution);
    sol::stack::raw_set_field(L, "friction", val.friction);
    return 1;
}
cocos2d::PhysicsMaterial sol_lua_get(sol::types<cocos2d::PhysicsMaterial>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    float density = t["density"];
    float restitution = t["restitution"];
    float friction = t["friction"];
    tracking.use(1);
    return { density,restitution,friction };
}

// Convert cocos2d::PhysicsRayCastInfo
int sol_lua_push(sol::types<cocos2d::PhysicsRayCastInfo>, lua_State* L, const cocos2d::PhysicsRayCastInfo& val) {
    lua_createtable(L, 0, 7);
    sol::stack::raw_set_field(L, "shape", val.shape);
    sol::stack::raw_set_field(L, "start", val.start);
    sol::stack::raw_set_field(L, "ended", val.end);
    sol::stack::raw_set_field(L, "contact", val.contact);
    sol::stack::raw_set_field(L, "normal", val.normal);
    sol::stack::raw_set_field(L, "fraction", val.fraction);
    if (val.data) {
        lua_pushliteral(L, "data");
        lua_pushlightuserdata(L, val.data);
        lua_rawset(L, -3);
    }
    return 1;
}

int sol_lua_push(sol::types<const cocos2d::PhysicsRayCastInfo*>, lua_State* L, const cocos2d::PhysicsRayCastInfo* val) {
    if (val) {
        sol_lua_push(sol::types<cocos2d::PhysicsRayCastInfo>(), L, *val);
    }
    else {
        lua_pushnil(L);
    }
    return 1;
}

int sol_lua_push(sol::types<cocos2d::PhysicsRayCastInfo*>, lua_State* L, const cocos2d::PhysicsRayCastInfo* val) {
    return sol_lua_push(sol::types<const cocos2d::PhysicsRayCastInfo*>(), L, val);
}
cocos2d::PhysicsRayCastInfo sol_lua_get(sol::types<cocos2d::PhysicsRayCastInfo>, lua_State* L, int idx, sol::stack::record& tracking) {
    int absIdx = lua_absindex(L, idx);
    sol::table t = sol::table(L, absIdx);// ...table...
    PhysicsShape* shape = t["shape"];
    Vec2 start = t["start"];
    Vec2 end = t["ended"];
    Vec2 contact = t["contact"];
    Vec2 normal = t["normal"];
    float fraction = t["fraction"];
    void* data = nullptr;
    lua_pushliteral(L, "data");// ...table..."data"
    if (LUA_TLIGHTUSERDATA == lua_rawget(L, absIdx)) {//...table...light_ud?
        data = const_cast<void*>(lua_topointer(L, -1));//...table...light_ud
    }
    lua_pop(L, 1);// ...table...
    tracking.use(1);
    return { shape,start,end,contact,normal,fraction,data };
}

// Convert cocos2d::PhysicsContactData
int sol_lua_push(sol::types<cocos2d::PhysicsContactData>, lua_State* L, const cocos2d::PhysicsContactData& val) {
    lua_createtable(L, 0, 2);// table
    lua_pushliteral(L, "points");// table,"point",subTable
    lua_createtable(L, 0, val.count);// table,"point",subTable
    for (int i = 0;i < val.count;i++) {
        sol::stack::raw_set_field(L, i + 1, val.points[i]);
    }
    lua_rawset(L, -3);// table
    sol::stack::raw_set_field(L, "normal", val.normal);
    return 1;
}
int sol_lua_push(sol::types<const cocos2d::PhysicsContactData*>, lua_State* L, const cocos2d::PhysicsContactData* val) {
    if (!val) {
        lua_pushnil(L);
    }
    else {
        sol_lua_push(sol::types<cocos2d::PhysicsContactData>(), L, *val);
    }
    return 1;
}
cocos2d::PhysicsContactData sol_lua_get(sol::types<cocos2d::PhysicsContactData>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    sol::table subT = t["points"];
    PhysicsContactData pcd = {};
    pcd.normal = t["normal"];
    pcd.count = 0;
    for (int i = 1;i <= PhysicsContactData::POINT_MAX;i++) {
        pcd.points[i - 1] = subT[i];
        pcd.count++;
    }
    tracking.use(1);
    return pcd;
}
#endif

// Convert cocos2d::Size
int sol_lua_push(sol::types<cocos2d::Size>, lua_State* L, const cocos2d::Size& val) {
    lua_createtable(L, 0, 2);
    sol::stack::raw_set_field(L, "width", val.width);
    sol::stack::raw_set_field(L, "height", val.height);
    return 1;
}
cocos2d::Size sol_lua_get(sol::types<cocos2d::Size>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    float width = t["width"];float height = t["height"];
    tracking.use(1);
    return { width,height };
}

// Convert cocos2d::Rect
int sol_lua_push(sol::types<cocos2d::Rect>, lua_State* L, const cocos2d::Rect& val) {
    lua_createtable(L, 0, 4);
    sol::stack::raw_set_field(L, "x", val.origin.x);
    sol::stack::raw_set_field(L, "y", val.origin.y);
    sol::stack::raw_set_field(L, "width", val.size.width);
    sol::stack::raw_set_field(L, "height", val.size.height);
    return 1;
}
cocos2d::Rect sol_lua_get(sol::types<cocos2d::Rect>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    float x = t["x"];float y = t["y"];
    float width = t["width"];float height = t["height"];
    tracking.use(1);
    return { {x,y},{width,height} };
}

// Convert cocos2d::Color4B
int sol_lua_push(sol::types<cocos2d::Color4B>, lua_State* L, const cocos2d::Color4B& val) {
    lua_createtable(L, 0, 4);
    sol::stack::raw_set_field(L, "r", val.r);
    sol::stack::raw_set_field(L, "g", val.g);
    sol::stack::raw_set_field(L, "b", val.b);
    sol::stack::raw_set_field(L, "a", val.a);
    return 1;
}
cocos2d::Color4B sol_lua_get(sol::types<cocos2d::Color4B>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    uint8_t r = t["r"];uint8_t g = t["g"];uint8_t b = t["b"];uint8_t a = t["a"];
    tracking.use(1);
    return { r,g,b,a };
}

// Convert cocos2d::Color4F
int sol_lua_push(sol::types<cocos2d::Color4F>, lua_State* L, const cocos2d::Color4F& val) {
    lua_createtable(L, 0, 4);
    sol::stack::raw_set_field(L, "r", val.r);
    sol::stack::raw_set_field(L, "g", val.g);
    sol::stack::raw_set_field(L, "b", val.b);
    sol::stack::raw_set_field(L, "a", val.a);
    return 1;
}
cocos2d::Color4F sol_lua_get(sol::types<cocos2d::Color4F>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    float r = t["r"];float g = t["g"];float b = t["b"];float a = t["a"];
    tracking.use(1);
    return { r,g,b,a };
}

// Convert cocos2d::Color3B
int sol_lua_push(sol::types<cocos2d::Color3B>, lua_State* L, const cocos2d::Color3B& val) {
    lua_createtable(L, 0, 3);
    sol::stack::raw_set_field(L, "r", val.r);
    sol::stack::raw_set_field(L, "g", val.g);
    sol::stack::raw_set_field(L, "b", val.b);
    return 1;
}
cocos2d::Color3B sol_lua_get(sol::types<cocos2d::Color3B>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    uint8_t r = t["r"];uint8_t g = t["g"];uint8_t b = t["b"];
    tracking.use(1);
    return { r,g,b };
}

// Convert cocos2d::AffineTransform
int sol_lua_push(sol::types<cocos2d::AffineTransform>, lua_State* L, const cocos2d::AffineTransform& val) {
    lua_createtable(L, 0, 6);
    sol::stack::raw_set_field(L, "a", val.a);
    sol::stack::raw_set_field(L, "b", val.b);
    sol::stack::raw_set_field(L, "c", val.c);
    sol::stack::raw_set_field(L, "d", val.d);
    sol::stack::raw_set_field(L, "tx", val.tx);
    sol::stack::raw_set_field(L, "ty", val.ty);
    return 1;
}
cocos2d::AffineTransform sol_lua_get(sol::types<cocos2d::AffineTransform>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    float a = t["a"];float b = t["b"];float c = t["c"];float d = t["d"];
    float tx = t["tx"];float ty = t["ty"];
    tracking.use(1);
    return { a,b,c,d,tx,ty };
}

// Convert cocos2d::FontDefinition
int sol_lua_push(sol::types<cocos2d::FontDefinition>, lua_State* L, const cocos2d::FontDefinition& val) {
    lua_createtable(L, 0, 11);//table

    lua_pushliteral(L, "shadow");//table,"shadow"
    lua_createtable(L, 0, 4);//table,"shadow",shadowTable
    sol::stack::raw_set_field(L, "offset", val._shadow._shadowOffset);
    sol::stack::raw_set_field(L, "blur", val._shadow._shadowBlur);
    sol::stack::raw_set_field(L, "opacity", val._shadow._shadowOpacity);
    sol::stack::raw_set_field(L, "enabled", val._shadow._shadowEnabled);
    lua_rawset(L, -3);//table

    lua_pushliteral(L, "stroke");//table,"stroke"
    lua_createtable(L, 0, 4);//table,"stroke",strokeTable
    sol::stack::raw_set_field(L, "size", val._stroke._strokeSize);
    sol::stack::raw_set_field(L, "color", val._stroke._strokeColor);
    sol::stack::raw_set_field(L, "alpha", val._stroke._strokeAlpha);
    sol::stack::raw_set_field(L, "enabled", val._stroke._strokeEnabled);
    lua_rawset(L, -3);//table

    sol::stack::raw_set_field(L, "fontName", val._fontName);
    sol::stack::raw_set_field(L, "fontSize", val._fontSize);
    sol::stack::raw_set_field(L, "fontColor", val._fontFillColor);
    sol::stack::raw_set_field(L, "fontAlpha", val._fontAlpha);
    sol::stack::raw_set_field(L, "hAlignment", val._alignment);
    sol::stack::raw_set_field(L, "vAlignment", val._vertAlignment);
    sol::stack::raw_set_field(L, "dimensions", val._dimensions);
    sol::stack::raw_set_field(L, "enableWrap", val._enableWrap);
    sol::stack::raw_set_field(L, "overflow", val._overflow);
    return 1;
}
cocos2d::FontDefinition sol_lua_get(sol::types<cocos2d::FontDefinition>, lua_State* L, int idx, sol::stack::record& tracking) {
    FontDefinition fd = {};
    sol::table t = sol::table(L, idx);

    auto shadow = t["shadow"];
    if (shadow.valid()) {
        fd._shadow._shadowOffset = shadow["offset"].valid() ? shadow["offset"] : Size::ZERO;
        fd._shadow._shadowBlur = shadow["blur"].valid() ? shadow["blur"] : 0.f;
        fd._shadow._shadowOpacity = shadow["opacity"].valid() ? shadow["opacity"] : 0.f;
        fd._shadow._shadowEnabled = shadow["enabled"].valid() ? shadow["enabled"] : false;
    }

    auto stroke = t["stroke"];
    if (stroke.valid()) {
        fd._stroke._strokeSize = stroke["size"].valid() ? stroke["size"] : 0.f;
        fd._stroke._strokeColor = stroke["color"].valid() ? stroke["color"] : Color3B::BLACK;
        fd._stroke._strokeAlpha = stroke["alpha"].valid() ? stroke["alpha"] : 0;
        fd._stroke._strokeEnabled = stroke["enabled"].valid() ? stroke["enabled"] : false;
    }

    fd._fontName = t["fontName"].valid() ? t["fontName"] : std::string();
    fd._fontSize = t["fontSize"].valid() ? t["fontSize"] : 0;
    fd._fontFillColor = t["fontColor"].valid() ? t["fontColor"] : Color3B::WHITE;
    fd._fontAlpha = t["fontAlpha"].valid() ? t["fontAlpha"] : 255;
    fd._alignment = t["hAlignment"].valid() ? t["hAlignment"] : TextHAlignment::CENTER;
    fd._vertAlignment = t["vAlignment"].valid() ? t["vAlignment"] : TextVAlignment::TOP;
    fd._dimensions = t["dimension"].valid() ? t["dimension"] : Size::ZERO;
    fd._enableWrap = t["enableWrap"].valid() ? t["enableWrap"] : true;
    fd._overflow = t["overflow"].valid() ? t["overflow"] : 0;

    tracking.use(1);
    return fd;
}

// Convert cocos2d::TTFConfig
int sol_lua_push(sol::types<cocos2d::TTFConfig>, lua_State* L, const cocos2d::TTFConfig& val) {
    lua_createtable(L, 0, 10);
    sol::stack::raw_set_field(L, "fontFilePath", val.fontFilePath);
    sol::stack::raw_set_field(L, "fontSize", val.fontSize);
    sol::stack::raw_set_field(L, "glyphs", val.glyphs);
    sol::stack::raw_set_field(L, "customGlyphs", val.customGlyphs);
    sol::stack::raw_set_field(L, "distanceFieldEnabled", val.distanceFieldEnabled);
    sol::stack::raw_set_field(L, "outlineSize", val.outlineSize);
    sol::stack::raw_set_field(L, "italics", val.italics);
    sol::stack::raw_set_field(L, "bold", val.bold);
    sol::stack::raw_set_field(L, "underline", val.underline);
    sol::stack::raw_set_field(L, "strikethrough", val.strikethrough);
    return 1;
}
cocos2d::TTFConfig sol_lua_get(sol::types<cocos2d::TTFConfig>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);

    std::string fontFilePath = t["fontFilePath"].valid() ? t["fontFilePath"] : std::string();
    float fontSize = t["fontSize"].valid() ? t["fontSize"] : static_cast<float>(CC_DEFAULT_FONT_LABEL_SIZE);
    GlyphCollection glyphs = t["glyphs"].valid() ? t["glyphs"] : GlyphCollection::DYNAMIC;
    char* customGlyphs = t["customGlyphs"].valid() ? t["customGlyphs"] : nullptr;
    bool distanceFieldEnabled = t["distanceFieldEnabled"].valid() ? t["distanceFieldEnabled"] : false;
    int outlineSize = t["outlineSize"].valid() ? t["outlineSize"] : 0;
    bool italics = t["italics"].valid() ? t["italics"] : false;
    bool bold = t["bold"].valid() ? t["bold"] : false;
    bool underline = t["underline"].valid() ? t["underline"] : false;
    bool strikethrough = t["strikethrough"].valid() ? t["strikethrough"] : false;

    tracking.use(1);
    return TTFConfig(fontFilePath, fontSize, glyphs, customGlyphs, distanceFieldEnabled, outlineSize, italics, bold, underline, strikethrough);
}

// Convert cocos2d::Mat4
int sol_lua_push(sol::types<cocos2d::Mat4>, lua_State* L, const cocos2d::Mat4& val) {
    lua_createtable(L, 16, 0);
    for (int i = 0; i < 16; i++) {
        sol::stack::raw_set_field(L, i + 1, val.m[i]);
    }
    return 1;
}
cocos2d::Mat4 sol_lua_get(sol::types<cocos2d::Mat4>, lua_State* L, int idx, sol::stack::record& tracking) {
    Mat4 mat4 = Mat4::IDENTITY;
    sol::table t = sol::table(L, idx);
    for (int i = 0;i < 16;i++) {
        mat4.m[i] = t[i + 1];
    }
    tracking.use(1);
    return mat4;
}

// Convert cocos2d::MeshVertexAttrib
int sol_lua_push(sol::types<cocos2d::MeshVertexAttrib>, lua_State* L, const cocos2d::MeshVertexAttrib& val) {
    lua_createtable(L, 0, 2);
    sol::stack::raw_set_field(L, "type", val.type);
    sol::stack::raw_set_field(L, "vertexAttrib", val.vertexAttrib);
    return 1;
}
cocos2d::MeshVertexAttrib sol_lua_get(sol::types<cocos2d::MeshVertexAttrib>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    backend::VertexFormat type = t["type"];
    shaderinfos::VertexKey vertexAttrib = t["vertexAttrib"];
    tracking.use(1);
    return { type,vertexAttrib };
}

// Convert cocos2d::Quaternion
int sol_lua_push(sol::types<cocos2d::Quaternion>, lua_State* L, const cocos2d::Quaternion& val) {
    return sol_lua_push(sol::types<cocos2d::Vec4>(), L, (const Vec4&)val);
}
cocos2d::Quaternion sol_lua_get(sol::types<cocos2d::Quaternion>, lua_State* L, int idx, sol::stack::record& tracking) {
    Vec4 val = sol_lua_get(sol::types<cocos2d::Vec4>(), L, idx, tracking);
    Quaternion* q = (Quaternion*)&val;
    return *q;
}

// Convert cocos2d::Texture2D::TexParams
int sol_lua_push(sol::types<cocos2d::Texture2D::TexParams>, lua_State* L, const cocos2d::Texture2D::TexParams& val) {
    lua_createtable(L, 0, 4);
    sol::stack::raw_set_field(L, "magFilter", val.magFilter);
    sol::stack::raw_set_field(L, "minFilter", val.minFilter);
    sol::stack::raw_set_field(L, "sAddressMode", val.sAddressMode);
    sol::stack::raw_set_field(L, "tAddressMode", val.tAddressMode);
    return 1;
}
cocos2d::Texture2D::TexParams sol_lua_get(sol::types<cocos2d::Texture2D::TexParams>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    backend::SamplerFilter magFilter = t["magFilter"].valid() ? t["magFilter"] : backend::SamplerFilter::LINEAR;
    backend::SamplerFilter minFilter = t["minFilter"].valid() ? t["minFilter"] : backend::SamplerFilter::LINEAR;
    backend::SamplerAddressMode sAddressMode = t["sAddressMode"].valid() ? t["sAddressMode"] : backend::SamplerAddressMode::CLAMP_TO_EDGE;
    backend::SamplerAddressMode tAddressMode = t["tAddressMode"].valid() ? t["tAddressMode"] : backend::SamplerAddressMode::CLAMP_TO_EDGE;
    tracking.use(1);
    return { magFilter,minFilter,sAddressMode,tAddressMode };
}

// Convert cocos2d::Tex2F
int sol_lua_push(sol::types<cocos2d::Tex2F>, lua_State* L, const cocos2d::Tex2F& val) {
    lua_createtable(L, 0, 2);
    sol::stack::raw_set_field(L, "u", val.u);
    sol::stack::raw_set_field(L, "v", val.v);
    return 1;
}
cocos2d::Tex2F sol_lua_get(sol::types<cocos2d::Tex2F>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    float u = t["u"];float v = t["v"];
    tracking.use(1);
    return { u,v };
}

// Convert cocos2d::V3F_C4B_T2F
int sol_lua_push(sol::types<cocos2d::V3F_C4B_T2F>, lua_State* L, const cocos2d::V3F_C4B_T2F& val) {
    lua_createtable(L, 0, 3);
    sol::stack::raw_set_field(L, "vertices", val.vertices);
    sol::stack::raw_set_field(L, "colors", val.colors);
    sol::stack::raw_set_field(L, "texCoords", val.texCoords);
    return 1;
}
cocos2d::V3F_C4B_T2F sol_lua_get(sol::types<cocos2d::V3F_C4B_T2F>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    Vec3 vertices = t["vertices"];
    Color4B colors = t["colors"];
    Tex2F texCoords = t["texCoords"];
    tracking.use(1);
    return { vertices,colors,texCoords };
}

// Convert cocos2d::backend::UniformLocation
int sol_lua_push(sol::types<cocos2d::backend::UniformLocation>, lua_State* L, const cocos2d::backend::UniformLocation& val) {
    lua_createtable(L, 0, 2);// table
    lua_pushliteral(L, "location");// table,"location"
    lua_createtable(L, 2, 0);//table,"location",locationTable
    sol::stack::raw_set_field(L, 1, val.location[0]);
    sol::stack::raw_set_field(L, 2, val.location[1]);
    lua_rawset(L, -3);// table
    sol::stack::raw_set_field(L, "shaderStage", val.shaderStage);
    return 1;
}
cocos2d::backend::UniformLocation sol_lua_get(sol::types<cocos2d::backend::UniformLocation>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    backend::UniformLocation ul = {};
    ul.shaderStage = t["shaderStage"];
    sol::table locTab = t["location"];
    for (int i = 0;i < 2;i++) {
        ul.location[i] = locTab[i + 1];
    }
    tracking.use(1);
    return ul;
}

// Convert cocos2d::backend::AttributeBindInfo
int sol_lua_push(sol::types<cocos2d::backend::AttributeBindInfo>, lua_State* L, const cocos2d::backend::AttributeBindInfo& val) {
    lua_createtable(L, 0, 4);
    sol::stack::raw_set_field(L, "attributeName", val.attributeName);
    sol::stack::raw_set_field(L, "location", val.location);
    sol::stack::raw_set_field(L, "size", val.size);
    sol::stack::raw_set_field(L, "type", val.type);
    return 1;
}
cocos2d::backend::AttributeBindInfo sol_lua_get(sol::types<cocos2d::backend::AttributeBindInfo>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    std::string attributeName = t["attributeName"];
    int location = t["location"];
    int size = t["size"];
    int type = t["type"];
    tracking.use(1);
    return { attributeName,location,size,type };
}

// Convert cocos2d::RZip::ZipInfo
int sol_lua_push(sol::types<cocos2d::RZip::ZipInfo>, lua_State* L, const cocos2d::RZip::ZipInfo& val) {
    lua_createtable(L, 0, 4);
    sol::stack::raw_set_field(L, "name", val.name);
    sol::stack::raw_set_field(L, "date", val.date);
    if (val.name.length() > 0 && val.name[val.name.length() - 1] != '/') {
        sol::stack::raw_set_field(L, "size", val.size);
        sol::stack::raw_set_field(L, "encrypt", val.encrypt);
    }
    return 1;
}

// Convert cocos2d::network::DownloaderHints
int sol_lua_push(sol::types<cocos2d::network::DownloaderHints>, lua_State* L, const cocos2d::network::DownloaderHints& val) {
    lua_createtable(L, 0, 3);
    sol::stack::raw_set_field(L, "countOfMaxProcessingTasks", val.countOfMaxProcessingTasks);
    sol::stack::raw_set_field(L, "tempFileNameSuffix", val.tempFileNameSuffix);
    sol::stack::raw_set_field(L, "timeoutInMS", val.timeoutInMS);
    return 1;
}
cocos2d::network::DownloaderHints sol_lua_get(sol::types<cocos2d::network::DownloaderHints>, lua_State* L, int idx, sol::stack::record& tracking) {
    static const cocos2d::network::DownloaderHints dh = {};
    sol::table t = sol::table(L, idx);
    uint32_t countOfMaxProcessingTasks = t.get_or("countOfMaxProcessingTasks", dh.countOfMaxProcessingTasks);
    std::string tempFileNameSuffix = t.get_or("tempFileNameSuffix", dh.tempFileNameSuffix);
    uint32_t timeoutInMS = t.get_or("timeoutInMS", dh.timeoutInMS);
    tracking.use(1);
    return { countOfMaxProcessingTasks,timeoutInMS,tempFileNameSuffix };
}

int sol_lua_push(sol::types<cocos2d::network::DownloadTask::ProgressInfo>, lua_State* L, const cocos2d::network::DownloadTask::ProgressInfo& val) {
    lua_createtable(L, 0, 4);
    sol::stack::raw_set_field(L, "totalBytesReceived", val.totalBytesReceived);
    sol::stack::raw_set_field(L, "totalBytesExpected", val.totalBytesExpected);
    sol::stack::raw_set_field(L, "speedInBytes", val.speedInBytes);
    sol::stack::raw_set_field(L, "bytesReceived", val.bytesReceived);
    return 1;
}

// Convert cocos2d::Data
int sol_lua_push(sol::types<cocos2d::Data>, lua_State* L, const cocos2d::Data& val) {
    auto buff = luaL_Buffer();
    char* str = luaL_buffinitsize(L, &buff, val.getSize());
    std::memcpy(str, val.getBytes(), val.getSize());
    luaL_pushresultsize(&buff, val.getSize());
    return 1;
}
cocos2d::Data sol_lua_get(sol::types<cocos2d::Data>, lua_State* L, int idx, sol::stack::record& tracking) {
    size_t strLen = 0;
    const uint8_t* str = reinterpret_cast<const uint8_t*>(luaL_checklstring(L, idx, &strLen));
    cocos2d::Data data = {};
    data.copy(str, strLen);
    tracking.use(1);
    return data;
}

// Convert cocos2d::ui::Margin
int sol_lua_push(sol::types<cocos2d::ui::Margin>, lua_State* L, const cocos2d::ui::Margin& val) {
    lua_createtable(L, 0, 4);
    sol::stack::raw_set_field(L, "left", val.left);
    sol::stack::raw_set_field(L, "top", val.top);
    sol::stack::raw_set_field(L, "right", val.right);
    sol::stack::raw_set_field(L, "bottom", val.bottom);
    return 1;
}
cocos2d::ui::Margin sol_lua_get(sol::types<cocos2d::ui::Margin>, lua_State* L, int idx, sol::stack::record& tracking) {
    sol::table t = sol::table(L, idx);
    const float left = t["left"];
    const float top = t["top"];
    const float right = t["right"];
    const float bottom = t["bottom"];
    tracking.use(1);
    return { left,top,right,bottom };
}

std::vector<char> sol_lua_get(sol::types<std::vector<char>>, lua_State* L, int idx, sol::stack::record& tracking) {
    size_t strLen = 0;
    const char* str = luaL_checklstring(L, idx, &strLen);
    auto vec = std::vector<char>(strLen);
    vec.insert(vec.end(), str, str + strLen);
    tracking.use(1);
    return vec;
}

std::vector<unsigned char> sol_lua_get(sol::types<std::vector<unsigned char>>, lua_State* L, int idx, sol::stack::record& tracking) {
    size_t strLen = 0;
    const unsigned char* str = reinterpret_cast<const unsigned char*>(luaL_checklstring(L, idx, &strLen));
    auto vec = std::vector<unsigned char>(strLen);
    vec.insert(vec.end(), str, str + strLen);
    tracking.use(1);
    return vec;
}

int sol_lua_push(sol::types<std::vector<char>>, lua_State* L, const std::vector<char>& val) {
    auto buff = luaL_Buffer();
    char* str = luaL_buffinitsize(L, &buff, val.size());
    std::memcpy(str, val.data(), val.size());
    luaL_pushresultsize(&buff, val.size());
    return 1;
}

int sol_lua_push(sol::types<std::vector<unsigned char>>, lua_State* L, const std::vector<unsigned char>& val) {
    auto buff = luaL_Buffer();
    char* str = luaL_buffinitsize(L, &buff, val.size());
    std::memcpy(str, val.data(), val.size());
    luaL_pushresultsize(&buff, val.size());
    return 1;
}

int sol_lua_push(sol::types<const std::vector<char>*>, lua_State* L, const std::vector<char>* val) {
    if (!val) {
        lua_pushnil(L);
        return 1;
    }
    return sol_lua_push(sol::types<std::vector<char>>(), L, *val);
}
int sol_lua_push(sol::types<const std::vector<unsigned char>*>, lua_State* L, const std::vector<unsigned char>* val) {
    if (!val) {
        lua_pushnil(L);
        return 1;
    }
    return sol_lua_push(sol::types<std::vector<unsigned char>>(), L, *val);
}
#version 330


layout(location = 0) in vec4 vPosition;
layout(location = 1) in vec2 vTextures;
layout(location = 2) in vec3 vNormal;

uniform vec4 diffuseColor;
uniform vec4 specularColor;
uniform vec4 ambientColor;
uniform vec4 vColorValue;
uniform mat4 mMVP;
uniform mat4 mMV;
uniform mat3 mNormal;
uniform vec3 vLight;
uniform int bShading;
uniform int bTextures;

smooth out vec4 vVaryingColor;
smooth out vec2 vVaryingTextures;
smooth out vec3 vVaryingNormal;
smooth out vec3 vVaryingLightDir;

void main(void)
{
    vec3 vLightDir;
    vec3 vEyeNormal;
    if(bShading == 1)
        {
        vEyeNormal = mNormal * vNormal;

        vec4 vPosition4 = mMV*vPosition;
        vec3 vPosition3 = vPosition4.xyz / vPosition4.w;

        vLightDir = normalize(vLight -vPosition3);
        float diff = max(0.0, dot(vEyeNormal, vLightDir));


        if(bTextures == 1)
            vVaryingTextures = vTextures;

        vVaryingColor = diff * vColorValue;

        vVaryingColor += ambientColor;

        vec3 vReflection = normalize(reflect(-vLightDir, vEyeNormal));

        float spec = max(0.0, dot(vEyeNormal, vReflection));
        if(diff != 0)
            {
            float fSpec = pow(spec, 128.0);
            vVaryingColor.rgb +=vec3(fSpec, fSpec, fSpec);
            }
        }
    else
        vVaryingColor = vColorValue;

    if(bTextures == 1)
        vVaryingTextures = vTextures;

   // vVaryingNormal = vNormal;
    vVaryingNormal = vEyeNormal;
    vVaryingLightDir = vLightDir;



    gl_Position =  mMVP * vPosition;


}


//#version 330


//layout(location = 0) in vec4 vPosition;
//layout(location = 2) in vec3 vNormal;

//uniform vec4 ambientColor;
//uniform vec4 vColorValue;
//uniform mat4 mMVP;
//uniform mat4 mMV;
//uniform mat3 mNormal;
//uniform vec3 vLight;

//smooth out vec4 vVaryingColor;

//void main(void)
//{
//vVaryingColor.r = 1.0;
//vVaryingColor.g = 1.0;
//vVaryingColor.b = 1.0;
//vVaryingColor.a = 1.0;

//gl_Position =  vPosition;
//}

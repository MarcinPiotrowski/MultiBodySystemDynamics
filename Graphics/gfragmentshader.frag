#version 330


uniform int bTextures;
uniform sampler2D colorMap;
uniform vec4 ambientColor;
uniform vec4 diffuseColor;
uniform vec4 specularColor;

smooth in vec4 vVaryingColor;
smooth in vec3 vVaryingLightDir;
smooth in vec3 vVaryingNormal;
smooth in vec2 vVaryingTextures;

out vec4 vFragColor;

//void main(void)
//{
//    if (bTextures == 1)
//        vFragColor = texture2D(colorMap, vVaryingTextures.st);
//    else
//        vFragColor = vVaryingColor;
//}

void main(void)
{
if (bTextures == 1)
    {
    // vec4 vSample = texture2D(colorMap, vVaryingTextures);
    // Dot product gives us diffuse intensity
    float diff = max(0.0, dot(normalize(vVaryingNormal), normalize(vVaryingLightDir)));
    // Multiply intensity by diffuse color, force alpha to 1.0
     vFragColor = diff * diffuseColor;
    // Add in ambient light
     vFragColor += ambientColor;

     // Modulate in the texture
     //vFragColor = vVaryingColor;


    // Specular Light
    vec3 vReflection = normalize(reflect(-normalize(vVaryingLightDir),
    normalize(vVaryingNormal)));
    float spec = max(0.0, dot(normalize(vVaryingNormal), vReflection));
    if(diff != 0)
        {
        float fSpec = pow(spec, 128.0);
        vFragColor.rgb += vec3(fSpec, fSpec, fSpec);
        }
     vFragColor *= texture2D(colorMap, vVaryingTextures);

  }

else
    {
    vFragColor = ambientColor;
    //vFragColor = vVaryingColor;
    }






}

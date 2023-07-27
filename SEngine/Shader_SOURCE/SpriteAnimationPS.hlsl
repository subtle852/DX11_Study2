#include "globals.hlsli"

struct VSIn
{
    float3 Pos : POSITION;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};

struct VSOut
{
    float4 Pos : SV_Position;
    float3 WorldPos : POSITION;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};


float4 main(VSOut In) : SV_TARGET
{
    float4 color = (float4) 0.0f;
    
    // 1200 1032 // 120 130
    // 1080 -> 540
    // -540 + 1200 
    color = albedoTexture.Sample(anisotropicSampler, In.UV);

    if (animationType == 0)
        discard;
    
    if (animationType == 1 || animationType == 2)
    {
        float2 diff = (AtlasSize - SpriteSize) / 2.0f;
        float2 UV = (SpriteLeftTop - diff - SpriteOffset)
                + (AtlasSize * In.UV);
    
        if (UV.x < SpriteLeftTop.x || UV.x > SpriteLeftTop.x + SpriteSize.x
            || UV.y < SpriteLeftTop.y || UV.y > SpriteLeftTop.y + SpriteSize.y)
            discard;
        
        if(animationType == 2) UV.x *= -1;
        
        color = atlasTexture.Sample(anisotropicSampler, UV);
    }
    
    color *= lightsAttribute[0].color;
    
    //float4 lightColor = float4(0.2f, 0.2f, 0.2f, 1.0f);
    float4 lightColor = float4(0.0f, 0.0f, 0.0f, 1.0f);
    
    //for (int i = 0; i < 2; i++)// i가 1일때, Back 애니메이션의 경우 빛의 밝기가 적용되지 않는 문제 발생
    {
        //CalculateLight2D(lightColor, In.WorldPos, i);
        CalculateLight2D(lightColor, In.WorldPos, 0);
    }
    
    color *= lightColor;
    
    return color;
}
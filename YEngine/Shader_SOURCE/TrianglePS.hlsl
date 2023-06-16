struct VSIn
{
    float3 Pos : POSITION;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};

struct VSOut
{
    float4 Pos : SV_Position;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};


// UV 좌표
// 화면 해상도와 텍스쳐 해상도가 다르니 이미지를 보간하기위한 샘플링
Texture2D smileTexture : register(t0);
SamplerState samplerState : register(s0);

float4 main(VSOut In) : SV_TARGET
{
    //return In.Color;
    
    float4 color = (float) 0.0f;
    color = smileTexture.Sample(samplerState, In.UV);
    
    return color;
}
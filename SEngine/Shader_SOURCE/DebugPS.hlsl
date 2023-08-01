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
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};


float4 main(VSOut In) : SV_TARGET
{
    float4 color = (float4) 0.0f;
    
    if (colliderState == 0)// NotColiding
    {
        color = float4(1.0f, 1.0f, 1.0f, 1.0f); // ���
    }
    else if (colliderState == 1)// IsColliding
    {
        color = float4(0.0f, 1.0f, 0.0f, 1.0f); // �ʷϻ�
    }
    //else if (colliderState == 2)// NoneActive
    //{
    //    color = float4(1.0f, 1.0f, 1.0f, 1.0f); // ���
    //}
    
        return color;
}
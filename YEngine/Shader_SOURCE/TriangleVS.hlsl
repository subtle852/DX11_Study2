//float4 main( float4 pos : POSITION ) : SV_POSITION
//{
//	return pos;
//}

//struct Vertex[3]
//{
//    Vector3 pos;
//    Vector4 color;
//};

struct VSIn
{
    float3 Pos : POSITION;
    float4 Color : COLOR;
};

struct VSOut
{
    float4 Pos : SV_Position;
    float4 Color : COLOR;
};

cbuffer Transform : register(b0)
{
    float4 Pos;
}

VSOut main(VSIn In)
{
    VSOut Out = (VSOut)0.0f;

    Out.Pos = float4(In.Pos, 1.0f);
    //Out.Pos.x += 0.4f; //inputPosX; -> ������۸� ���ؼ� �̵����Ͱ� �ѿ;��Ѵ�.
    Out.Pos.x += Pos.x;
    
    Out.Color = In.Color;
    
    // sin();

    return Out;
}
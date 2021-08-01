
cbuffer ObjectTransform:register(b0)
{
	matrix World;
	matrix View;
	matrix Projection;
	float4 viewPos;
    float4 time;
};




struct VIn{
    float3 Position:POSITION;
    float3 Normal:NORMAL;
    float2 TexCoord:TEXCOORD;
};

struct VOut{
    float4 Pos:SV_POSITION;
    float3 PosW:POSITION;
    float3 NormalW:NORMAL;
    float2 TexCoord:TEXCOORD;
};


VOut vsmain( VIn vin )
{
    VOut vout;
    float3 nV=vin.Position;

    

    vout.Pos=mul(float4(nV,1),World);
    vout.Pos=mul(vout.Pos,View);
    vout.Pos=mul(vout.Pos,Projection);
    vout.PosW=vin.Position;

    float4 normal4=mul(float4(vin.Normal,0),World);

    vout.NormalW.x=normal4.x;
    vout.NormalW.y=normal4.y;
    vout.NormalW.z=normal4.z;
    vout.TexCoord=float2(0,0);
    return vout;
}

 float4 psmain( VOut pin ) : SV_Target
 {
    float4 viewDir=normalize(viewPos-float4(pin.PosW,1));
    float4 n4=float4(pin.NormalW,0);
    float df=dot(viewDir,n4);
	float4 f4={1,1,1,1};
    return float4(df*f4.x,df*f4.y,f4.z*df,1);
 }
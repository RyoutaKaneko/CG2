#include "Basic.hlsli"

Texture2D<float4> tex : register(t0);//0番スロットに設定されているテクスチャ
SamplerState smp : register(s0);	//0番スロットに設定されているサンプル


float4 main(VSOutput input) : SV_TARGET{
	/*return float4(tex.Sample(smp,input.uv));*/
	return float4(1,1,1,1);
}
#include "Basic.hlsli"

Texture2D<float4> tex : register(t0);//0�ԃX���b�g�ɐݒ肳��Ă���e�N�X�`��
SamplerState smp : register(s0);	//0�ԃX���b�g�ɐݒ肳��Ă���T���v��


float4 main(VSOutput input) : SV_TARGET{
	return float4(input.normal,1) * color;
	//return float4(1,1,1,1);
}
// �`�悷��e�N�X�`��
sampler Texture : register( s0 ) ;

float4 pos : register(c0);



struct OutPut
{
	float4 color0:COLOR0;
};


OutPut main(float2 uv : TEXCOORD0)//���͒l
{
	OutPut o;

	o.color0 = tex2D(Texture, uv);

	return o;
}
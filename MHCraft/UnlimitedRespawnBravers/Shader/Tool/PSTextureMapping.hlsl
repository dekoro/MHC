// 描画するテクスチャ
sampler Texture : register( s0 ) ;

float4 pos : register(c0);



struct OutPut
{
	float4 color0:COLOR0;
};


OutPut main(float2 uv : TEXCOORD0)//入力値
{
	OutPut o;

	o.color0 = tex2D(Texture, uv);

	return o;
}
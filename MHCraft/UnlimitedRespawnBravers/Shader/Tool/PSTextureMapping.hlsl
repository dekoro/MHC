// 描画するテクスチャ
sampler Texture : register( s0 ) ;

float b : register(c0);


float4 main(float2 uv : TEXCOORD0) : COLOR//入力値
{
	float4 color = (float4)0;


	color = tex2D(Texture, uv);

	if (b == 1)
	{
		//color.rgb = 1 - color.rgb;
		color.rgb = 1 - color.rgb;
	}


	return color;
}
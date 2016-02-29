// 描画するテクスチャ
sampler Texture0 : register( s0 ) ;

float Shift : register(c0);
float CenterX : register(c1);
float CenterY : register(c2);
float Alpth : register(c3);


float4 main(float2 texCoord  : TEXCOORD0) : COLOR
{
	float weight = 0.2;
	float totalWeight = (float2)0;
	float4 color = (float4)0;
		float2 center = normalize(texCoord - float2(CenterX, CenterY));

		for (int i = 0; i < 10; i++)
		{
			color += tex2D(Texture0, texCoord) * weight;

			texCoord += Shift * center;

			totalWeight += weight;

		}
	return (color / totalWeight)  * Alpth;
}
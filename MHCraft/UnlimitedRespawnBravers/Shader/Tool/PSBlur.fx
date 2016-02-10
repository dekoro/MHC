sampler Texture0 : register(s0);
float4 Direction : register(c0);

float4 main( float2 texCoord  : TEXCOORD0 ) : COLOR
{
   float weight = 0.2f;//透明度
   float totalWeight = 0;//合計の透明度
   float4 color = (float4)0;//色
   
   for(int i = 0; i < 10;++i)
   {
      color += tex2D( Texture0, texCoord ) * weight;
      
      texCoord += normalize(Direction.xy) * Direction.z;
      
      totalWeight += weight; 
   }
   
   return (color/totalWeight) ;
}


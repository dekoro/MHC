sampler Texture0 : register(s0);
float4 Direction : register(c0);

float GetRandam(float2 texCoord)
{
   int speed = 32;
   return  frac(sin(dot(texCoord.xy,float2(12.9898,78.233)) + speed) * 43758.5453);
}


float4 main( float2 texCoord  : TEXCOORD0 ) : COLOR
{
   float weight = 0.2f;//透明度
   float totalWeight = 0;//合計の透明度
   float4 color = (float4)0;//色
   const float PI = 3.14;
   float2 accuracy = sin((PI/360) * GetRandam(texCoord)) * 0.5;
   
   
   for(int i = 0; i < 10;++i)
   {
      color += tex2D( Texture0, texCoord ) * weight;
      
      texCoord += normalize(Direction.xy) * Direction.z;

      texCoord += accuracy;   
      
      totalWeight += weight; 
   }
   
   return (color/totalWeight) ;
}


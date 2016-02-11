sampler Texture0 : register( s0 ) ;

float4 slope : register(c0);

float4 main( float2 texCoord  : TEXCOORD0 ) : COLOR
{   
   float y = (slope.z* slope.x) + slope.y;
   float originX = 0.5;
   float2 li = float2(1,y);
//line‚Æ‚¢‚¤–¼‘O‚ªƒGƒ‰[‚É‚È‚é‚Á‚Û‚¢
   float2 origin = float2(originX,(slope.z*originX) + slope.y);
   float2 vec = origin.xy - texCoord.xy ;
   li = origin.xy - li.xy ;
   
   float3 cr = cross(float3(vec.xy,0), float3(li.xy,0));

   if(cr.z > 0)
   {
       return (float4)0;
   }   
  
   
   return tex2D(Texture0,texCoord);
}


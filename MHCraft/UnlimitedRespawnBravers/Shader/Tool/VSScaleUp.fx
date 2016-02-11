float4x4 Wold : register(c94);
float4x4 Projection : register(c2);
float4x4 View : register(c6);

float4 main(float4 pos : POSITION) : POSITION
{
   pos = mul(pos,Wold);
   
   pos = mul(pos,View);

   pos = mul(pos,Projection);

   return pos;
}
float4x4              cfProjectionMatrix   : register(c2);		// ビュー　　→　射影行列
float4x4              cfViewMatrix         : register(c6);		// ワールド　→　ビュー行列
float4              cfLocalWorldMatrix[162]   : register(c94);		// ローカル　→　ワールド行列
float4				oldMatrix[162]	  : register(c155); //オールドポジション

struct VS_INPUT
{
	float4 Position : POSITION;
	int4 BlendIndices : BLENDINDICES0;
	float4 BlendWeight : BLENDWEIGHT0;
	int4 BlendIndices2 : BLENDINDICES1;
	float4 BlendWeight2 : BLENDWEIGHT1;
	float4 Normal:NORMAL;


};

float4 main(VS_INPUT input) :POSITION
{
	float4 outPos;
	float4 lWorldPosition;
	float4 lViewPosition;

	float4 lOldPosition;
	float4 lLocalWorldMatrix[3] = (float4[3])0;

	//////////////////
	//複数のフレームのブレンド行列作成

	lLocalWorldMatrix[0] = cfLocalWorldMatrix[input.BlendIndices.x + 0] * input.BlendWeight.x;
	lLocalWorldMatrix[1] = cfLocalWorldMatrix[input.BlendIndices.x + 1] * input.BlendWeight.x;
	lLocalWorldMatrix[2] = cfLocalWorldMatrix[input.BlendIndices.x + 2] * input.BlendWeight.x;

	lLocalWorldMatrix[0] += cfLocalWorldMatrix[input.BlendIndices.y + 0] * input.BlendWeight.y;
	lLocalWorldMatrix[1] += cfLocalWorldMatrix[input.BlendIndices.y + 1] * input.BlendWeight.y;
	lLocalWorldMatrix[2] += cfLocalWorldMatrix[input.BlendIndices.y + 2] * input.BlendWeight.y;

	lLocalWorldMatrix[0] += cfLocalWorldMatrix[input.BlendIndices.z + 0] * input.BlendWeight.z;
	lLocalWorldMatrix[1] += cfLocalWorldMatrix[input.BlendIndices.z + 1] * input.BlendWeight.z;
	lLocalWorldMatrix[2] += cfLocalWorldMatrix[input.BlendIndices.z + 2] * input.BlendWeight.z;

	lLocalWorldMatrix[0] += cfLocalWorldMatrix[input.BlendIndices.w + 0] * input.BlendWeight.w;
	lLocalWorldMatrix[1] += cfLocalWorldMatrix[input.BlendIndices.w + 1] * input.BlendWeight.w;
	lLocalWorldMatrix[2] += cfLocalWorldMatrix[input.BlendIndices.w + 2] * input.BlendWeight.w;

	lLocalWorldMatrix[0] += cfLocalWorldMatrix[input.BlendIndices2.x + 0] * input.BlendWeight2.x;
	lLocalWorldMatrix[1] += cfLocalWorldMatrix[input.BlendIndices2.x + 1] * input.BlendWeight2.x;
	lLocalWorldMatrix[2] += cfLocalWorldMatrix[input.BlendIndices2.x + 2] * input.BlendWeight2.x;

	lLocalWorldMatrix[0] += cfLocalWorldMatrix[input.BlendIndices2.y + 0] * input.BlendWeight2.y;
	lLocalWorldMatrix[1] += cfLocalWorldMatrix[input.BlendIndices2.y + 1] * input.BlendWeight2.y;
	lLocalWorldMatrix[2] += cfLocalWorldMatrix[input.BlendIndices2.y + 2] * input.BlendWeight2.y;

	lLocalWorldMatrix[0] += cfLocalWorldMatrix[input.BlendIndices2.z + 0] * input.BlendWeight2.z;
	lLocalWorldMatrix[1] += cfLocalWorldMatrix[input.BlendIndices2.z + 1] * input.BlendWeight2.z;
	lLocalWorldMatrix[2] += cfLocalWorldMatrix[input.BlendIndices2.z + 2] * input.BlendWeight2.z;

//	lLocalWorldMatrix[0] += cfLocalWorldMatrix[input.BlendIndices2.w + 0] * input.BlendWeight2.w;
//	lLocalWorldMatrix[1] += cfLocalWorldMatrix[input.BlendIndices2.w + 1] * input.BlendWeight2.w;
//	lLocalWorldMatrix[2] += cfLocalWorldMatrix[input.BlendIndices2.w + 2] * input.BlendWeight2.w;

	/////////////////過去のポジションのウェイト計算

	lLocalWorldMatrix[0] = oldMatrix[input.BlendIndices.x + 0] * input.BlendWeight.x;
	lLocalWorldMatrix[1] = oldMatrix[input.BlendIndices.x + 1] * input.BlendWeight.x;
	lLocalWorldMatrix[2] = oldMatrix[input.BlendIndices.x + 2] * input.BlendWeight.x;

	lLocalWorldMatrix[0] += oldMatrix[input.BlendIndices.y + 0] * input.BlendWeight.y;
	lLocalWorldMatrix[1] += oldMatrix[input.BlendIndices.y + 1] * input.BlendWeight.y;
	lLocalWorldMatrix[2] += oldMatrix[input.BlendIndices.y + 2] * input.BlendWeight.y;

	lLocalWorldMatrix[0] += oldMatrix[input.BlendIndices.z + 0] * input.BlendWeight.z;
	lLocalWorldMatrix[1] += oldMatrix[input.BlendIndices.z + 1] * input.BlendWeight.z;
	lLocalWorldMatrix[2] += oldMatrix[input.BlendIndices.z + 2] * input.BlendWeight.z;

	lLocalWorldMatrix[0] += oldMatrix[input.BlendIndices.w + 0] * input.BlendWeight.w;
	lLocalWorldMatrix[1] += oldMatrix[input.BlendIndices.w + 1] * input.BlendWeight.w;
	lLocalWorldMatrix[2] += oldMatrix[input.BlendIndices.w + 2] * input.BlendWeight.w;

	lLocalWorldMatrix[0] += oldMatrix[input.BlendIndices2.x + 0] * input.BlendWeight2.x;
	lLocalWorldMatrix[1] += oldMatrix[input.BlendIndices2.x + 1] * input.BlendWeight2.x;
	lLocalWorldMatrix[2] += oldMatrix[input.BlendIndices2.x + 2] * input.BlendWeight2.x;

	lLocalWorldMatrix[0] += oldMatrix[input.BlendIndices2.y + 0] * input.BlendWeight2.y;
	lLocalWorldMatrix[1] += oldMatrix[input.BlendIndices2.y + 1] * input.BlendWeight2.y;
	lLocalWorldMatrix[2] += oldMatrix[input.BlendIndices2.y + 2] * input.BlendWeight2.y;

	lLocalWorldMatrix[0] += oldMatrix[input.BlendIndices2.z + 0] * input.BlendWeight2.z;
	lLocalWorldMatrix[1] += oldMatrix[input.BlendIndices2.z + 1] * input.BlendWeight2.z;
	lLocalWorldMatrix[2] += oldMatrix[input.BlendIndices2.z + 2] * input.BlendWeight2.z;

//	lLocalWorldMatrix[0] += oldMatrix[input.BlendIndices2.w + 0] * input.BlendWeight2.w;
//	lLocalWorldMatrix[1] += oldMatrix[input.BlendIndices2.w + 1] * input.BlendWeight2.w;
//	lLocalWorldMatrix[2] += oldMatrix[input.BlendIndices2.w + 2] * input.BlendWeight2.w;

	//////////////////////
	lWorldPosition.x = dot(input.Position, lLocalWorldMatrix[0]);
	lWorldPosition.y = dot(input.Position, lLocalWorldMatrix[1]);
	lWorldPosition.z = dot(input.Position, lLocalWorldMatrix[2]);

	lWorldPosition.w = 1.0f;


	////////////過去のポジションの計算

	lOldPosition.x = dot(input.Position, oldMatrix[0]);
	lOldPosition.y = dot(input.Position, oldMatrix[1]);
	lOldPosition.z = dot(input.Position, oldMatrix[2]);

	lOldPosition.w = 1.0f;

	///////////

	//移動方向
	float3 Dir = lWorldPosition - lOldPosition;

	float a = dot(normalize(Dir),normalize(input.Normal));


	if (a < 0.0f)
	{
		lWorldPosition = lOldPosition;
	}
	
	//lWorldPosition =  mul(pos,cfLocalWorldMatrix);	


	lViewPosition = mul(lWorldPosition, cfViewMatrix);

	lViewPosition.w = 1.0f;

	outPos = mul(lViewPosition, cfProjectionMatrix);

	return outPos;
}
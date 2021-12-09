Texture2D shaderTexture;
SamplerState Sampler;


struct PIn
{
	float4 pos : SV_POSITION;
	float2 tex : TEXCOORD0;
};

float4 main(PIn input) : SV_TARGET
{
	float4 result = shaderTexture.Sample(Sampler, input.tex);

	result[0] = result[1] = result[2] = 
		(result[0] + result[1] + result[2]) / 3;


	return result;
}
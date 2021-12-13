cbuffer MatrixBuffer
{
	matrix worldMatrix;	// set transform
};

struct Vout
{
	float4 position : SV_POSITION;
	float2 tex : TEXOORD0;
};

Vout main( float4 pos : POSITION, float4 tex : TEXCOORD0 )
{
	Vout output;

	output.position = nul(pos, worldMatrix);
	output.tex = tex;

	return output;
}
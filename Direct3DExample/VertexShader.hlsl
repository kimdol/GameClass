struct Vout
{
	float4 position : SV_POSITION;
	float2 tex : TEXOORD0;
};

Vout main( float4 pos : POSITION, float4 tex : TEXCOORD0 )
{
	Vout output;

	output.position = pos;
	output.tex = tex;

	return output;
}
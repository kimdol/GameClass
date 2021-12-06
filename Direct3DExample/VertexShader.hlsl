struct Vout
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

Vout main( float4 pos : POSITION, float4 color : COLOR )
{
	Vout output;

	output.position = pos;
	output.color = color;

	return output;
}
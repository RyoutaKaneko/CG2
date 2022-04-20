float4 main(float4 pos : POSITION) : SV_POSITION
{
	const float PI = 3.141519;
	float angle = PI * 0.25f;
	float4 pos2 = pos;

	pos2.x = pos.x * cos(angle) - pos.y * sin(angle);
	pos2.y = pos.x * sin(angle) + pos.y * cos(angle);
	return pos2;
}
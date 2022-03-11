#pragma once
class Vector
{
public:
	Vector(float x, float y)
	{
		_x = x;
		_y = y;
	}

	float x() { return _x; }
	float y() { return _y; }

private:
	float _x;
	float _y;
};
#pragma once
class Vector
{
public:
	Vector(float x, float y) : _x(x), _y(y)
	{}

	float x() const { return _x; }
	float y() const { return _y; }

private:
	float _x;
	float _y;
};
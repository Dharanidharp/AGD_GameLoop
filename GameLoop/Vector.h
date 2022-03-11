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

	void setX(float x_val) 
	{
		_x = x_val;
	}

	void setY(float y_val)
	{
		_y = y_val;
	}

private:
	float _x;
	float _y;
};
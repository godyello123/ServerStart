#pragma once

#include <memory.h>

class GEMath
{
};


class GEVector
{
public:
	GEVector() : x(0), y(0), z(0), w(0)
	{

	}
	GEVector(int _x, int _y, int _z = 0, int _w = 0) :
		x(static_cast<float>(_x)), y(static_cast<float>(_y)),
		z(static_cast<float>(_z)), w(static_cast<float>(_w))
	{

	}
	GEVector(const GEVector& _Other) = delete;

public:
	float x; 
	float y;
	float z; 
	float w;


public:
	int ix() const
	{
		return static_cast<int>(x);
	}

	int iy() const
	{
		return static_cast<int>(y);
	}

	int iz() const
	{
		return static_cast<int>(z);
	}

	int iw() const
	{
		return static_cast<int>(w);
	}

	GEVector& operator=(const GEVector& _Other)
	{
		memcpy_s(this, sizeof(GEVector), &_Other, sizeof(GEVector));
	}
};

typedef GEVector float4;
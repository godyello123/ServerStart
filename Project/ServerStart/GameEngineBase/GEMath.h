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
	GEVector(const GEVector& _Other)	: x(_Other.x), y(_Other.y), z(_Other.z), w(_Other.w)
	{
	}

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

	int CenterX() const
	{
		return ix() / 2;
	}

	int CenterY() const
	{
		return iy() / 2;
	}

	int CenterZ() const
	{
		return iz() / 2;
	}

	int CenterW() const
	{
		return iw() / 2;
	}


	GEVector& operator=(const GEVector& _Other)
	{
		memcpy_s(this, sizeof(GEVector), &_Other, sizeof(GEVector));
		return *this;
	}
};

typedef GEVector float4;
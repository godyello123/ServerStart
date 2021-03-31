 #pragma once

#include <memory.h>

/*
$id$
*/

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
	GEVector(const GEVector& _Other) : x(_Other.x), y(_Other.y), z(_Other.z), w(_Other.w)
	{

	}

public:
	static const GEVector LEFT;
	static const GEVector RIGHT;
	static const GEVector UP;
	static const GEVector DOWN;

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

	inline int hix() const
	{
		// return (int)(x);
		return ix() / 2;
	}

	inline int hiy() const
	{
		return iy() / 2;
	}

	GEVector& operator=(const GEVector& _Other)
	{
		memcpy_s(this, sizeof(GEVector), &_Other, sizeof(GEVector));
		return *this;
	}

	GEVector& operator +=(const GEVector& _Other)
	{
		x += _Other.x;
		y += _Other.y;
		z += _Other.z;
		return *this;
	}

	GEVector operator +(const GEVector& _other)
	{
		GEVector vec;
		vec.x = x + _other.x;
		vec.y = x + _other.x;
		vec.z = x + _other.x;
		return vec;
	}
};

typedef GEVector float4;
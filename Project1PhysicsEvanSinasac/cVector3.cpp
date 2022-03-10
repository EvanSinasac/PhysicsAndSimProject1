//Evan Sinasac - 1081418
//INFO6019 Physics & Simulation (Project 1)
//cVector3.cpp description:
//				Functions implemented as defined for vectors

#include "cVector3.h"
#include <float.h>
#include <math.h>


//Initialize the vector with 0s
cVector3::cVector3()
	//: x(0.f), y(0.f), z(0.f)
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
	
} 


//Initialize the vector with the contents of another vector
cVector3::cVector3(const cVector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
} 


//Operator to copy the contents of a vector to this vector
cVector3& cVector3::operator=(const cVector3& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}
	return *this;
} 


//Initialize vector to have the same value for x, y and z
cVector3::cVector3(float value)
{
	x = value;
	y = value;
	z = value;
}


//Initialize vector with given values
cVector3::cVector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}


//Destructor for cVector3
cVector3::~cVector3()
{
	
}


//Calculate and return the length of the vector
float cVector3::Length()
{
	return sqrtf(Length2());
}


//Calculate and return the square of the length of the vector
float cVector3::Length2()
{
	return (x * x) + (y * y) + (z * z);
}


//Set all values of the vector to 0
void cVector3::Zeros()
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
}


//Invert the direction of the vector (multiply by -1)
void cVector3::Invert()
{
	operator*=(-1);
	//x = -x;
	//y = -y;
	//z = -z;
}


//Normalize the vector
void cVector3::Normalize()
{
	float len = Length();
	if (len != 0.f)
	{
		x /= len;
		y /= len;
		z /= len;
	}
}


//Scalar multiplication of the vector
void cVector3::operator*=(const float value)
{
	x *= value;
	y *= value;
	z *= value;
}


//Scalar division of the vector
void cVector3::operator/=(const float value)
{
	if (value != 0)
	{
		x /= value;
		y /= value;
		z /= value;
	}
}


//Vector addition (adding other vector to this vector)
void cVector3::operator+=(const cVector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}


//Vector subtraction (subtracting other vector from this vector)
void cVector3::operator-=(const cVector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}


//Scalar and Vector multiplication, returns a new vector
cVector3 operator*(const cVector3& vec, const float value)
{
	return cVector3(vec.x * value, vec.y * value, vec.z * value);
}


//Scalar and Vector division, returns a new vector
cVector3 operator/(const cVector3& vec, const float value)
{
	return cVector3(vec.x / value, vec.y / value, vec.z / value);
}


//Vector subtraction, returns a new vector
cVector3 operator-(const cVector3& a, const cVector3& b)
{
	return cVector3(a.x - b.x, a.y - b.y, a.z - b.z);
}


//Vector addition, returns a new vector
cVector3 operator+(const cVector3& a, const cVector3& b)
{
	return cVector3(a.x + b.x, a.y + b.y, a.z + b.z);
}


//Perform component multiplication, not used very often
cVector3 componentProduct(const cVector3& a, const cVector3& b)
{
	return cVector3(a.x * b.x, a.y * b.y, a.z * b.z);
}


//Scalar "Dot" Product
// a.b = ax*bx + ay*by + az*bz
float scalarProduct(const cVector3& a, const cVector3& b)
{;
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}


//Vector "Cross" Product, fun little thing to find the vector that is perpendicular to both inputted vectors
//	[ aybz - azby ]
//	[ azbx - axbz ]
//	[ axby - aybx ]
cVector3 vectorProduct(const cVector3& a, const cVector3& b)
{
	return cVector3((a.y*b.z - a.z*b.y), 
					(a.z*b.x - a.x*b.z), 
					(a.x*b.y - a.y*b.x));
}
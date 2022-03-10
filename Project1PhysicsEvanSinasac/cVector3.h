//Evan Sinasac - 1081418
//INFO6019 Physics & Simulation (Project 1)
//cVector3.h description:
//			3 floats (x, y, z) to represent the vector coordinates in 3D space
//			basic constructors for initializing vectors in different ways, and operators we will need

#pragma once

class cVector3
{
public:
	//floats x, y and z are used as coordinates of the vector
	//float v[3];
	//struct
	//{
		float x;
		float y;
		float z;
	//};
	// Default Constructor.
	// Initialize this vector to zeros.
	cVector3();
	// Copy Constructor
	// Initialize this vector to the same contents as a given vector.
	cVector3(const cVector3& other);
	// Copy Assignment
	// Initialize this vector to the same contents as a given vector.
	cVector3& operator=(const cVector3& other);
	// Parameterized Constructor
	// Initialize each component of this vector to a given value.
	cVector3(float value);
	// Parameterized Constructor
	// Initialize this vector to the given given values.
	cVector3(float _x, float _y, float _z);
	// Destructor
	~cVector3();

	// Calculate and return the length of this vector.
	float Length();
	// Calculate and return the squared length of this vector.
	float Length2();
	// Set all the values of this vector to zero.
	void Zeros();
	// Invert the direction of this vector.
	void Invert();
	// Normalize this vector.
	void Normalize();

	// 2.1.3 Scalar and Vector Multiplication
	void operator*=(const float value);
	void operator/=(const float value);

	// 2.1.4 Vector Addition and Subtraction
	void operator+=(const cVector3& other);
	void operator-=(const cVector3& other);
};  

// 2.1.3 Scalar and Vector Multiplication
cVector3 operator*(const cVector3& vec, const float value);
cVector3 operator/(const cVector3& vec, const float value);
// 2.1.4 Vector Addition and Subtraction
cVector3 operator-(const cVector3& a, const cVector3& b);
cVector3 operator+(const cVector3& a, const cVector3& b);
// 2.1.5 Multiplying Vectors
// 2.1.6 The Component Product
// Perform component-wise multiplication and return the result.
cVector3 componentProduct(const cVector3& a, const cVector3& b);
// 2.1.7 The Scalar/Dot Product
// Calculate the dot product of two vectors and return the result.
float scalarProduct(const cVector3& a, const cVector3& b);
inline float dotProduct(const cVector3& a, const cVector3& b) { return scalarProduct(a, b); }
// 2.1 8 The Vector Product
// Calculate the cross-product of two vectors and return the result.
cVector3 vectorProduct(const cVector3& a, const cVector3& b);
inline cVector3 crossProduct(const cVector3& a, const cVector3& b) { return vectorProduct(a, b); }


//Evan Sinasac - 1081418
//INFO6019 Physics & Simulation (Project 1)
//cMatrix3x3.cpp description:
//				Functions implemented as defined for matrices

#include "cMatrix3x3.h"


//Default constructor to the Identity matrix
cMatrix3x3::cMatrix3x3()
	//: xColumn(1.f, 0.f, 0.f), yColumn(0.f, 1.f, 0.f), zColumn(0.f, 0.f, 1.f)
{
	xColumn = cVector3(1.f, 0.f, 0.f);
	yColumn = cVector3(0.f, 1.f, 0.f);
	zColumn = cVector3(0.f, 0.f, 1.f);
}


//Initialize the matrix to another matrix
cMatrix3x3::cMatrix3x3(const cMatrix3x3& other)
{
	xColumn = other.xColumn;
	yColumn = other.yColumn;
	zColumn = other.zColumn;
}


//Initialize a new matrix to the contents of another matrix
cMatrix3x3& cMatrix3x3::operator=(const cMatrix3x3& other)
{
	if (this != &other)
	{
		xColumn = other.xColumn;
		yColumn = other.yColumn;
		zColumn = other.zColumn;
	}
	return *this;
}


//Initialize to a diagonal with the given value
cMatrix3x3::cMatrix3x3(float value)
	//: xColumn(value, 0.f, 0.f), yColumn(0.f, value, 0.f), zColumn(0.f, 0.f, value)
{
	xColumn = cVector3(value, 0.f, 0.f);
	yColumn = cVector3(0.f, value, 0.f);
	zColumn = cVector3(0.f, 0.f, value);
}


//Initialize the matrix with the given COLUMN vectors
cMatrix3x3::cMatrix3x3(const cVector3& xCol, const cVector3& yCol, const cVector3& zCol)
{
	xColumn = xCol;
	yColumn = yCol;
	zColumn = zCol;
}


//Destructor for cMatrix3x3
cMatrix3x3::~cMatrix3x3()
{

}


//Given two independent vectors, create a 3x3 matrix that represents an orthonormalBasis
cMatrix3x3 orthonormalBasis(const cVector3& xVec, const cVector3& zVec)
{
	//Using the given x and z axes, generate the y axis using the vector "cross" product
	cVector3 tempX(xVec);
	cVector3 tempZ(zVec);
	//cVector3 tempY = vectorProduct(tempZ, tempX);
	cVector3 tempY(crossProduct(tempZ, tempX));
	if (tempY.Length2() == 0.f)
	{
		return cMatrix3x3(1.0f);
	}
	tempZ = crossProduct(tempX, tempY);		//Ensure that z is orthogonal to both x and y
	//Normalize the axes
	tempX.Normalize();  
	tempY.Normalize();  
	tempZ.Normalize();  
	return cMatrix3x3(tempX, tempY, tempZ);
} 
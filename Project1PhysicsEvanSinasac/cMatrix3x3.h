//Evan Sinasac - 1081418
//INFO6019 Physics & Simulation (Project 1)
//cMatrix3x3.h description:
//				9 floats for the 3x3 matrix
//				basic constructors for initializing a 3x3 matrix, and orthonormalBasis axes

#pragma once
#include "cVector3.h"


class cMatrix3x3
{
public:
	
	//3 cVector3 to represent each column of the matrix, with the left column representing the xColumn, then yColumn, then zColumn
	//cVector3 xColumn;
	//cVector3 yColumn;
	//cVector3 zColumn;

	union
	{
		float m[9];
		cVector3 cols[3];
		struct
		{
			cVector3 xColumn;
			cVector3 yColumn;
			cVector3 zColumn;
		};
	};
	// Default Constructor
	// Initialize this matrix to an Identity.
	cMatrix3x3();
	// Copy Constructor
	// Initialize this matrix to the same contents as a given matrix.
	cMatrix3x3(const cMatrix3x3& other);
	// Copy Assignment
	// Initialize this matrix to the same contents as a given matrix.
	cMatrix3x3& operator=(const cMatrix3x3& other);
	// Parameterized Constructor
	// Initialize this matrix to a Diagonal, with a given value.
	cMatrix3x3(float value);
	// Parameterized Constructor
	// Initialize this matrix to given column vectors.
	cMatrix3x3(const cVector3& xCol, const cVector3& yCol, const cVector3& zCol);
	// Destructor
	~cMatrix3x3();
};

// Generate an orthonormal basis, given two linearly independent vectors.
// The input vectors are unaffected.
cMatrix3x3 orthonormalBasis(const cVector3& xVec, const cVector3& zVec);

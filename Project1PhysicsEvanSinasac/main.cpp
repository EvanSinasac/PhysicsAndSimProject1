//Evan Sinasac - 1081418
//INFO6019 Physics & Simulation (Project 1)
//main.cpp description:
//				For Project 1, our objective is to complete the given To Dos from the starting code for the cMatrix and cVector3 stuff, 
//				Implement the missing steps of the main function and fill out the other functions, in particular,
//				particleIsAboveGround, particleIsMovingUpward, doTimeStepEuler, doTimeStepMidpoint
//				This program simulates a single particle launched from just above the ground until it hits the ground

#include "cVector3.h"    // cVector3 class
#include "cMatrix3x3.h"  // cMatrix3x3 class
#include <iostream>      // outputs
#include <cstdlib>       // for rand()
#include <time.h>        // for seeding

// Generate a random number between 0 and 1
float getRandom();

// Generate a random number between zero and a given high value
float getRandom(float high);

// Generate a random number in a given range
float getRandom(float low, float high);

// Returns a vector laying on the x-z plane, randomized in direction and magnitude.
// The output is designed to be linearly independent from the output of getRandomZVector()
cVector3 getRandomXVector();

// Returns a vector laying on the x-z plane, randomized in direction and magnitude.
// The output is designed to be linearly independent from the output of getRandomXVector()
cVector3 getRandomZVector();

// Determine from the parameters if the particle is currently above the ground.
bool particleIsAboveGround(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration);

// Determine from the parameters if the particle is currently moving "up".
bool particleIsMovingUpward(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration);

// Perform one single time-step implementing Euler Integration.
void doTimeStepEuler(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration);
// Perform one single time-step implementing Midpoint Integration.
void doTimeStepMidpoint(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration);

// The main function
int main()
{
	// Step 1: Seed the random number generation.
	unsigned int uiTime = static_cast<unsigned int>(time(NULL));
	std::cout << "uiTime: " << uiTime << std::endl;
	srand(uiTime);
	// Step 2: Generate a random basis for the axes.
	//         If done correctly, the x and z axes will be randomized only in the x-z plane
	//         and the y axis will always be (0, 1, 0)
	cMatrix3x3 axes = orthonormalBasis(getRandomXVector(), getRandomZVector());
	std::cout << "OrthoNormalBasis = [ " << axes.xColumn.x << ", \t" << axes.yColumn.x << ", \t" << axes.zColumn.x << "\t]" << std::endl;
	std::cout << "OrthoNormalBasis = [ " << axes.xColumn.y << ", \t" << axes.yColumn.y << ", \t" << axes.zColumn.y << "\t\t]" << std::endl;
	std::cout << "OrthoNormalBasis = [ " << axes.xColumn.z << ", \t" << axes.yColumn.z << ", \t" << axes.zColumn.z << "\t]" << std::endl;

	// Step 3: Generate a random velocity for the particle.
	// Step 3.1: The position starts just above the ground.
	cVector3 position(0.0, 0.1f, 0.0);
	// Step 3.2: Generate a random velocity with a larger y value (relative to the x and z)
	//cVector3 velocity(getRandom(-10.f, 10.f), getRandom(10.f, 50.f), getRandom(-10.f, 10.f));
	//Generate x, y and z components for the velocity from the axes by multiplying the axes by random scalar numbers
	//cVector3 xComponent = axes.xColumn;		xComponent.operator*=(getRandom(-10.f, 10.f));
	//cVector3 yComponent = axes.yColumn;		yComponent.operator*=(getRandom(10.f, 50.f));
	//cVector3 zComponent = axes.zColumn;		zComponent.operator*=(getRandom(-10.f, 10.f));
	//Add the three components to generate the initial velocity
	//cVector3 velocity(xComponent + yComponent + zComponent);
	
	//I thought I tried this and it didn't work, lol
	cVector3 velocity = (axes.xColumn * getRandom(-2.f, 2.f)) + (axes.yColumn * 5.f) + (axes.zColumn * getRandom(-2.f, 2.f));
	
	std::cout << "velocity = [ " << velocity.x << ", " << velocity.y << ", " << velocity.z << " ]" << std::endl;
	velocity.Normalize();				//Normalize the velocity,
	velocity.operator*=(10);			//then multiply by 10 to have magnitude 10
	std::cout << "velocity(magnitude 10) = [ " << velocity.x << ", " << velocity.y << ", " << velocity.z << " ]" << std::endl;
	std::cout << "Velocity Magnitude = " << velocity.Length() << std::endl;
	
	// Step 4: Define the acceleration due to gravity, and deltaTime.
	cVector3 acceleration(0.f, -9.8f, 0.f);
	float deltaTime = 0.03f;

	// Step 5: Enter the main loop.
	// Track the total elapsed simulation time.
	float timeElapsed = 0;


	// Continue the simulation so long as the particle is above the ground.
	while (particleIsAboveGround(axes, deltaTime, timeElapsed, position, velocity, acceleration))
	{
		if (particleIsMovingUpward(axes, deltaTime, timeElapsed, position, velocity, acceleration))
		{
			// Let the user know the particle is moving up.
			std::cout << "going up! \tx=" << position.x << "\ty=" << position.y << "\tz=" << position.z << std::endl;
		} 
		else
		{
			// Let the user know the particle is moving down.
			std::cout << "going down! \tx=" << position.x << "\ty=" << position.y << "\tz=" << position.z << std::endl;
		} 

		// Step the simulation forward
		//doTimeStepEuler(axes, deltaTime, timeElapsed, position, velocity, acceleration);
		doTimeStepMidpoint(axes, deltaTime, timeElapsed, position, velocity, acceleration);
		//std::cout << std::endl;
	} 
	std::cout << "Impacted after " << timeElapsed << " seconds with a velocity x=" << velocity.x << "\ty=" << velocity.y << "\tz=" << velocity.z << std::endl;

	//std::system("pause");
	return 0;
}

float getRandom()
{
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

float getRandom(float high)
{
	return static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / high);
} 

float getRandom(float low, float high)
{
	return low + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (high - low));
} 

// Use as-is.  Do not change.
cVector3 getRandomXVector()
{
	return cVector3(getRandom(0.1f, 1.f), 0.f, getRandom(0.1f, 1.f));
} 

// Use as-is.  Do not change.
cVector3 getRandomZVector()
{
	return cVector3(-getRandom(0.1f, 1.f), 0.f, getRandom(0.1f, 1.f));
} 

bool particleIsAboveGround(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration)
{
	//A particle is Above the Ground if it is above the XZ-plane, i.e., y > 0 if y is positive in the axes, y < 0 if y is negative in the axes
	//i.e. A particle is Above the Ground if it's position is in the same direction as 'up', which is the direction of the y-axis
	//The scalarProduct tells us if two vectors are relatively in the same direction (if result positive), opposite (if result is negative)
/*	float r = scalarProduct(axes.yColumn, position);
	if (r > 0)
	{
		return true;
	}*/ //was going to do checking if 0 but got my properties mixed up, if scalarProduct returns 0 then they are perpendicular, which I've decided is not the same direction anyways
	
	if (position.y > 0.f)
		return true;

	return false;
}

bool particleIsMovingUpward(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration)
{
	//A particle is Moving Upward if the y-component of the velocity is in the reltively same direction as the y-axis
	//float vIsUp = scalarProduct(axes.yColumn, velocity);
	//if (vIsUp > 0)
	//{
	//	return true;
	//} //was going to do checking if 0 but got my properties mixed up, if scalarProduct returns 0 then they are perpendicular, which I've decided is not the same direction anyways
	//return false;

	return dotProduct(velocity, axes.yColumn) > 0.f;
} 

void doTimeStepEuler(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration)
{
	//Euler Integration Algorithm:
	//r(position)n+1 = rn + r'dt
	//rn+1 = rn + vndt
	//vn+1 = vn + andt
	position += (velocity * deltaTime);
	velocity += (acceleration * deltaTime);
	
	//std::cout << "Eul rn+1 = [ " << position.x << ", " << position.y << ", " << position.z << " ]" << std::endl;
	//std::cout << "Eul vn+1 = [ " << velocity.x << ", " << velocity.y << ", " << velocity.z << " ]" << std::endl;
	
	timeElapsed += deltaTime;
}

void doTimeStepMidpoint(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration)
{
	//Midpoint Integration Algorithm:
	//rn+1 = rn + (vn + vn+1)dt/2
	//vn+1 = vn + andt
	cVector3 vOld(velocity);
	velocity += (acceleration * deltaTime);
	position += (vOld + velocity) * (deltaTime/2.f);
	
	//std::cout << "Mid vn = [ " << vOld.x << ", " << vOld.y << ", " << vOld.z << " ]" << std::endl;
	//std::cout << "Mid vn+1 = [ " << velocity.x << ", " << velocity.y << ", " << velocity.z << " ]" << std::endl;
	//std::cout << "Mid r = [ " << position.x << ", " << position.y << ", " << position.z << " ]" << std::endl;
	
	timeElapsed += deltaTime;
}
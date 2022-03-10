INFO6019 Physics & Simulation (Project 1)
Evan Sinasac - 1081418

I built and compiled using Visual Studios 2019 in Debug and 64 bit.
I tested and it should work in 32 bit and in Release for both 64 and 32 bit.

There is an executable in the x64 folder on the solution level but it does not keep the console open to view the steps in the simulation, so please run through Visual Studio (or uncomment line 104 in main.cpp)

To switch between running doTimeStepEuler and doTimeStepMidpoint, switch which line of 98 or 99 is commented.  Do not comment both lines as that will create an infinite loop.

I decided to keep the lines that print the OrthoNormalBasis to the console (lines 54-56), the initial velocity [line 69 (nice)], the velocity after having it's magnitude changed to 10 and it's magnitude (lines 72, 73) because it provides nice context for where the particle is starting and what the axes we're using actually are.

I found watching the actual velocity change during run time was interesting, but cluttered up the console too much.  If these are wanted, then uncomment lines 168 and 169 for doTimeStepEuler, and lines 183-185 for doTimeStepMidpoint.

Otherwise, everything else was done as defined.  I decided to go with 3 floats to represent the x, y and z coordinates for a vector, and 3 vector columns to represent the 3x3 Matrix, and followed the algorithms/math for each function from there.

Any additional explanation should be within comments about any specific functions or the math performed in the program.

Thanks for reading, have a lovely day!
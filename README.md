# Arduino-with-VS
Combines some projects using Arduino and Visual Studios. Most project will build in C++. 

List of Projects:
* Simple Serial Communication (Completed) 2018.6.10 
 
  Use Visual Studio 2017 to receive data from Arduino.   
  > Notice that the type of project must be "Visual C++  CLR Console Application" to  access the `System::IO::ports` namespace.
  
* Serial Communication Test (Completed) 2018.6.11

  Use Arduino to send three integer data via USB serail port and receive by computer via `System::IO::ports` namespace. Then, in order to get the real value of integers, we use two standard libraries in C++: `string.h` and `sstream.h`. By `sstream`, we can use `stringstream` namespace to send the serial infomation into stringstream type variables and print out as integer numbers. 
  > Notice that the type of project must be "Visual C++  CLR Console Application" to  access the `System::IO::ports` namespace.
  
* IMU 3D Simulation (Completed) 2018.6.13

  Use Visual Studio 2017 to read the IMU data from Arduino and plot the 3D graph with OpenGL. 
  
  > Notice that the type of project must be "Visual C++  CLR Console Application" to  access the `System::IO::ports` namespace.

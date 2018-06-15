# Arduino-with-VS
Combines some projects using Arduino and Visual Studios. Most project will build in C++. 

List of Projects:
* Simple Serial Communication (Completed)                                                                       
  - *Completed Data: 2018.6.10*
 
  Use Visual Studio 2017 to receive data from Arduino.   
  > Notice that the type of project must be "Visual C++  CLR Console Application" to  access the `System::IO::ports` namespace.
  
* Serial Communication Test (Completed)   
  - *Completed Data: 2018.6.11*

  Use Arduino to send three integer data via USB serail port and receive by computer via `System::IO::ports` namespace. Then, in order to get the real value of integers, we use two standard libraries in C++: `string.h` and `sstream.h`. By `sstream`, we can use `stringstream` namespace to send the serial infomation into stringstream type variables and print out as integer numbers. 
  > Notice that the type of project must be "Visual C++  CLR Console Application" to  access the `System::IO::ports` namespace.
  
* IMU 3D Simulation (Completed)    
   - *Completed Data: 2018.6.13*

  Use Visual Studio 2017 to read the IMU data from Arduino and plot the 3D graph with OpenGL.   
  To use the openGL to plot the graph, I used "freeGLUT" and "GLEW" library. You can download from [here](http://www.mediafire.com/file/cmlnr0pj0pyha5d/Glew+and+Glut.zip). To install the GLUT, following this [video](https://www.youtube.com/watch?v=8p76pJsUP44) (for visual studio 2015 to 2017).   
     
  For the code in Visual C++  CLR Console Application project, use the default `.cpp` file and use [this](https://www.ntu.edu.sg/home/ehchua/programming/opengl/CG_Examples.html) example. I did some modifications to read the data from Arduino via USB serial port. The additional function I added are `MarshelString` and `serial`. The first function is used to translate C# string type `String ^` which is default type when using `System::IO::Ports` namespace into C++ standard string type `string`. The second function is used to receive the data from Arduino and print in console by `std::cout`.    
     
  In order to keep reading when openGL/GLUT is working, I define the `serial` function as the parameter in GLUT callback function `glutIdleFunc`. With this, the GLUT will keep doing the `display` function and doing the `serial` when GLUT is idling.   
     
  Additionally, there are some tricky code there in
  ``` C++
  ref struct Port {
 	   static SerialPort^ port = gcnew SerialPort("COM3", 9600);
   };
  ```
  Why I create this structure is because the class `SerialPort` is ref class which I can't define it as a global ref object. To let the other functions "see" the address of `port`, I need to define a struct to store the ref class. I took [this](https://social.msdn.microsoft.com/Forums/vstudio/en-US/4da834f0-d8f8-4abb-a655-ef9e99d51eb2/how-to-create-a-global-object-of-a-ref-class-type?forum=vcgeneral) as my reference to do this trick.
  
  > Notice that the type of project must be "Visual C++  CLR Console Application" to  access the `System::IO::ports` namespace.

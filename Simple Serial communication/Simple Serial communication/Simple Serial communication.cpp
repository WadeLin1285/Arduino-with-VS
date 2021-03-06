#include "stdafx.h"
#include <iostream>

/* For port communication, we need these namespaces */
using namespace System;
using namespace System::IO::Ports;

int main(array<System::String ^> ^args)
{
	SerialPort port("COM7", 9600); // define the serial port ref class
	port.Open();                   // open the USB port  [NOTE: Don't put these two operations into loop. They can only execute once.]
	Console::WriteLine("Start");

	while (true) // keep reading the serial buffer
	{
		// Method 1 - ReadLine
		String^ message = port.ReadLine();
		Console::WriteLine(message);

		// Method 2 - Read each characters once
		//int message = port.ReadChar();
		//Console::WriteLine(Convert::ToChar(message));
	}

	return 0;
}


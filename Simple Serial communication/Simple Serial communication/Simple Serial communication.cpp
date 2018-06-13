#include "stdafx.h"
#include <iostream>

using namespace System;
using namespace System::IO::Ports;

int main(array<System::String ^> ^args)
{
	SerialPort port("COM7", 9600);
	port.Open();
	Console::WriteLine("Start");
	while (true)
	{
		String^ message = port.ReadLine();
		Console::WriteLine(message);
		//int message = port.ReadChar();
		//Console::WriteLine(Convert::ToChar(message));
	}
	return 0;
}


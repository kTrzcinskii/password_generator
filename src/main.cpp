#include "PasswordGenerator.h"
#include <stdexcept>
#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		password_generator::PasswordGenerator pg(argc, argv);
		pg.generate();
	}
	catch (const std::invalid_argument&)
	{
		//this exception is thrown when somehting was wrong with arguments
		//the message is already displayed and right here we only want to exit the program
		std::cout << "\nTry running the program again with valid arguments!\n";
		exit(1);
	}
	return 0;
}
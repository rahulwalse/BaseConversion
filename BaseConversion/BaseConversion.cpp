/* BaseConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.*/
/*
	This program is an implementation in C++ of algorithm for converting decimal integer number to itscorresponding
	octal representation including supplementary problems and algorithms for base conversions used for converting
	binary to octal, binary to decimal etc., from the book "How to Solve it by Computer" by R.G. Dromey.
*/

#include <iostream>
#include "conversionf.h"
using namespace std;
const int FIRSTOPTION = 1, LASTOPTION = 3;

int main()
{
	int base, choice;	long long int number;	char conti;
	/*Display the title of the program.*/
	cout << "\nProgram to convert and display numbers with diffeerent base and to represent in different number systems." << endl;
	for (int column = 1; column < 121; column++)
		cout << "=";	/*Printing a line of '='.*/

	do
	{
		cout << "\n1. Convert decimal integer number to corresponding binary, ternary, octal representations\n2. Binary to octal conversion";
		cout << "\n3. Binary to decimal conversion\nEnter your choice: " << endl;
		cin >> choice;
		/*Check if the choice is valid, if invalid then exit the program.*/
		if (choice < FIRSTOPTION || choice > LASTOPTION)
		{
			cout << "The option you selected is invalid. Exiting the program..." << endl;
			return 0;
		}
		else
		{
			switch (choice)
			{
				case 1:	cout << "\nEnter the decimal number to be converted to binary,ternary etc." << endl;
						cout << "Decimal Number=";	cin >> number;
						cout << "\nEnter value for base (2 for binary, 3 for ternary or 8 for octal and so on.)" << endl;
						cout << "Base=";	cin >> base;
						BaseChange(number, base);
						break;

				case 2:	cout << "\nEnter the binary number to be converted to its equivalent octal number." << endl;
						cin >> number;
						BinaryToOctal(number);
						break;

				case 3:	cout << "\nEnter the binary number to be converted to its equivalent deciaml number." << endl;
						cin >> number;
						BinaryToDecimal(number);
						break;
			}
		}
		/*Check if the user wants to continue.*/
		cout << "\nDo you want to continue (Y/N)?" << endl;
		cin >> conti;
	} while (conti == 'Y' || conti == 'y');
}
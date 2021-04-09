/*
	Implementation for converting binary number to its equivalent decimal number.
*/

#include<iostream>
#include "conversionf.h"
using namespace std;

int BinaryToDecimal(long long int binaryNumber)
{
	long long int quotient = binaryNumber, decimalNumber = 0;	int binaryBase = 2, digitPower = 0;
	/*While the quottient is not 0, add the product of rightmost bianry digit and base (2) to the digitPower and store in decimalNumber.*/
	while (quotient>0)
	{
		decimalNumber += ((quotient % 10) * Exponent(binaryBase, digitPower));
		digitPower = digitPower + 1;
		quotient = quotient / 10;	/*Chop off the rightmost digit.*/
	}
	/*Display the converted decimal number.*/
	cout << "\nThe decimal representation for binary number " << binaryNumber << " is " << decimalNumber << endl;
	return 0;
}
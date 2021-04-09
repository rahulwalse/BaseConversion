/*
	Implementation for converting binary number to corresponding octal number.
*/

#include <iostream>
#include "conversionf.h"
#define MAX 100
using namespace std;

void BinaryToOctal(long long int binaryNumber)
{
	/*
		To convert a binary number to its equivalent octal number, we have to convert the binary 
		number into a decimal number and then convert the resultant decimal number into octal number.
	*/
	long long int binaryQuotient = binaryNumber, decimalNumber = 0;	int binaryBase = 2, digitPower = 0;
	int octalRemainder, octalBase = 8, octalDigit = 0;	char zero = '0', ascii, octalNumber[MAX];
	if (binaryNumber == 0)
	{
		cout << "\nThe corresponding representation of binary number " << binaryNumber << " in octal is " << binaryNumber << endl;
	}
	else
	{
		/*Convert the binary number to equivalent decimal number.*/
		while (binaryQuotient > 0)
		{
			/*Adding the product of rightmost binary digit and binaryBase^digitPower to decimalNumber.*/
			decimalNumber += ((binaryQuotient % 10) * (Exponent(binaryBase, digitPower)));
			digitPower = digitPower + 1;
			binaryQuotient = binaryQuotient / 10;	/*Chopping off the rightmost digit.*/
		}

		long long int octalQuotient = decimalNumber;

		/*Now convert the decimal number to equivalent octal number.*/
		while (octalQuotient > 0)
		{
			/*
				Store the remainder of octalQuotient/octalBase in octalRemainder and get the ascii value by
				adding value of character 0 and octalremainder, store ascii (least significant digit) character
				in octalNumber array.
			*/
			octalRemainder = octalQuotient % octalBase;
			octalDigit = octalDigit + 1;
			ascii = zero + octalRemainder;
			octalNumber[octalDigit] = ascii;
			octalQuotient = octalQuotient / octalBase;
		}
		/*Display the digits stored in octalNumber array in reverse order.*/
		cout << "\nThe corresponding representation of binary number " << binaryNumber << " in octal is ";
		for (int index = octalDigit; index >= 1; index--)
		{
			cout << octalNumber[index];
		}
	}
}
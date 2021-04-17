/*
	Implementation for converting the decimal number to its equivalent Binary Coded Decimal (BCD) number.
*/

#include <iostream>
#define MAX 100
using namespace std;

int DecimalToBCD(long long int number)
{
	long long int DecimalNumber = number;	int DecimalDigit = 0, BCDWidth = 4;

	int BinaryDigit, InsertBCDPosition = 0, NextBCDDigit;
	char ASCII, ZERO = '0', BCDNumber[MAX];

	/*Initialize all the elements of the array BCDNumber to 0.*/
	for (int index = 0; index < MAX; index++)
	{
		BCDNumber[index] = '0';
	}
	/*When the decimal number is 0.*/
	if (number == 0)
	{
		cout << "\nThe corresponding representation of decimal number " << number << " in Binary Coded Decimal (BCD) number is:" << endl;
		cout << "Decimal Number: " << number << "\nBCD Number: ";
		for (int Position = 0; Position < 4; Position++)
		{
			cout << BCDNumber[Position];
		}
	}
	else
	{
		while (DecimalNumber > 0)
		{
			/*Get the right most digit of decimal number and store it in NewQuotient.*/
			DecimalDigit = DecimalNumber % 10;
			int NewQuotient = DecimalDigit;

			while (NewQuotient > 0)
			{
				/*
					Store the remainder of NewQuotient/2 in BinaryDigit, get the ASCII value by adding
					character 0 and BinarDigit, store the ASCII (least significant bit) character in the
					BCDNumber array.
				*/
				BinaryDigit = NewQuotient % 2;
				InsertBCDPosition = InsertBCDPosition + 1;
				ASCII = ZERO + BinaryDigit;
				BCDNumber[InsertBCDPosition] = ASCII;
				NewQuotient = NewQuotient / 2;
			}
			/*
				Because each decimal digit is of width 4 in BCD, we calculate the difference in current insert
				position and the beginning of next BCD number (4 bits wide) in the array to store the bits at
				those positions in array.
			*/
			NextBCDDigit = BCDWidth - InsertBCDPosition;
			BCDWidth = BCDWidth + 4;
			InsertBCDPosition += NextBCDDigit;
			DecimalNumber = DecimalNumber / 10;	/*Chop of the next right most digit of decimal number.*/
		}

		/*Display the equivalent BCD number, stored in reverse order.*/
		cout << "\nThe corresponding representation of decimal number " << number << " in Binary Coded Decimal (BCD) number is" << endl;
		cout << "Decimal Number: " << number << "\nBCD Number:";
		for (int Position = InsertBCDPosition; Position >= 1; Position--)
		{
			if (Position % 4 == 0)
				cout << " ";	/*Add a blank space after every 4 bits.*/
			cout << BCDNumber[Position];
		}
	}
	return 0;
}
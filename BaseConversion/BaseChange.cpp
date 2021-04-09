/*
	Implementation for converting decimal integer number to corresponding octal number.
*/

#include <iostream>
#define MAX 100
using namespace std;

int BaseChange(long long int number, int base)
{
	int remainder, quotient = number, digitCount = 0;	char ascii, zero = '0', convertedNumber[MAX];
	/*
		While the quotient is not zero, we store remainder of quotient/base in remainder, increase the digitCount by 1
		and add the remainder to zero and store in ascii to get the ascii value of the digit (least significant digit).
	*/
	if (number == 0)
	{
		cout << "\nThe corresponding representation for decimal number " << number << " with base " << base << " is " << number << endl;
	}
	else
	{
		while (quotient > 0)
		{
			remainder = quotient % base;
			digitCount = digitCount + 1;
			ascii = zero + remainder;
			/*If the ascii value is greater than 57 i.e. character 9, then add 7 to get character A onwards.*/
			if (ascii > '9')
			{
				ascii = ascii + 7;
			}
			convertedNumber[digitCount] = ascii;
			quotient = quotient / base;
		}

		cout << "\nThe corresponding representation for decimal number " << number << " with base " << base << " is ";
		/*Displaying the numbers stored in array convertedNumber in reverse order.*/
		for (int index = digitCount; index >= 1; index--)
		{
			cout << convertedNumber[index];
		}
	}
	return 0;
}
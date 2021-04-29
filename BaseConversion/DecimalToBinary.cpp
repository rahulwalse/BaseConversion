/*
	Implementation of method for converting given decimal number -- including fractional
	part -- to its equivalent binary number representation.
*/

#include <iostream>
#define MAX 50
using namespace std;

void DecimalToBinary(double Number)
{
	int BinaryInteger[MAX], BinaryFraction[MAX];
	int IntegerInsert = 0, FractionInsert = 0, BinaryBase = 2, BinaryRemainder, BinaryQuotient, Accuracy = 1, BinaryBit;

	/*Seperate the integer and decimal part of the number.*/
	int DecimalInteger = int(Number);
	double DecimalFraction = Number - DecimalInteger;

	/*Initialize the elements of BinaryInteger & BinaryFraction arrays to 0.*/
	for (int Index = 0; Index < MAX; Index++)
	{
		BinaryInteger[Index] = 0;
		BinaryFraction[Index] = 0;
	}

	/*Convert the integer part of the decimal number.*/
	BinaryQuotient = DecimalInteger;
	while (BinaryQuotient > 0)
	{
		BinaryRemainder = BinaryQuotient % 2;
		IntegerInsert = IntegerInsert + 1;
		BinaryInteger[IntegerInsert] = BinaryRemainder;
		BinaryQuotient = BinaryQuotient / 2;
	}

	/*Convert the fraction part of the decimal number.*/
	while (DecimalFraction != 0 && Accuracy <= 20)
	{
		DecimalFraction = DecimalFraction * 2;
		BinaryBit = DecimalFraction;
		FractionInsert = FractionInsert + 1;
		Accuracy++;
		BinaryFraction[FractionInsert] = BinaryBit;
		if (DecimalFraction >= 1)
			DecimalFraction = DecimalFraction - BinaryBit;
	}

	cout << "\nThe corresponding representation of binary number for decimal number " << Number << " is ";
	/*Display the integer part binary number, stored in BinaryInteger array in reverse order.*/
	if (DecimalInteger == 0)
		cout << BinaryInteger[IntegerInsert];
	else
	{
		for (int IntegerIndex = IntegerInsert; IntegerIndex >= 1; IntegerIndex--)
			cout << BinaryInteger[IntegerIndex];
	}

	/*Display the fractional part of the binary number, stored in BinaryFraction array.*/
	if (DecimalFraction != 0)	/*Display fractional part only when value is non-zero.*/
	{
		cout << ".";	/*Insert the decimal point before fractional part.*/
		for (int FractionIndex = 1; FractionIndex <= FractionInsert; FractionIndex++)
			cout << BinaryFraction[FractionIndex];
	}
}
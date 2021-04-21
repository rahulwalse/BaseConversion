/*
	Implementation of function to convert decimal fraction to its equivalent binary fraction with
	accuracy of 10 fractional digits.
*/

#include <iostream>
#define MAX 100
using namespace std;

void DecimalFractionToBinary(double DecimalFraction)
{
	double OriginalNumber = DecimalFraction;
	int BinaryFraction[MAX], Accuracy = 1, BinaryBit = 0, IntegerPart;
	/*Initialize all elements in the BinaryFraction to 0.*/
	for (int Index = 0; Index < MAX; Index++)
	{
		BinaryFraction[Index] = 0;
	}
	/*Remove the integral part (left of decimal point), if it is greater than 0.*/
	if (OriginalNumber>=1)
	{
		int Integral = OriginalNumber;
		OriginalNumber = OriginalNumber - Integral;
	}

	while (OriginalNumber != 0 && Accuracy <= 10)
	{
		/*Multiply the OriginalNumber with 2 and seperate and store the integral part in array.*/
		OriginalNumber = OriginalNumber * 2;
		IntegerPart = OriginalNumber;
		BinaryBit = BinaryBit + 1;
		BinaryFraction[BinaryBit] = IntegerPart;
		Accuracy++;
		/*Remove the integral part (left of decimal point) of OriginalNumber, if it is greater than 0.*/
		if (OriginalNumber>=1)
			OriginalNumber = OriginalNumber - IntegerPart;
	}

	if (OriginalNumber==0)
	{
		cout << "\nThe equivalent binary fractional part of decimal number " << DecimalFraction << " is .";
		cout << BinaryFraction[BinaryBit];
	}
	else
	{
		/*Display equivalent binary fractional part stored in array BinaryFraction.*/
		cout << "\nThe equivalent binary fractional part of decimal number " << DecimalFraction << " is .";
		for (int Index = 1; Index <= BinaryBit; Index++)
		{
			cout << BinaryFraction[Index];
		}
	}
}
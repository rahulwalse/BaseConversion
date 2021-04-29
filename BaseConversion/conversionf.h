/*
	This header file contains all the declarations of the functions used for converting a given
	decimal number to the corresponding octal, binary or hexadecimal number.
*/

#ifndef CONVERSIONF_H
#define CONVERSIONF_H

int BaseChange(long long int number, int base);
void BinaryToOctal(long long int binaryNumber);
int BinaryToDecimal(long long int binaryNumber);
int DecimalToBCD(long long int number);
void DecimalFractionToBinary(double DecimalFraction);
void DecimalToBinary(double Number);

int Exponent(int base, int number);

#endif /* !CONVERSIONF_H*/
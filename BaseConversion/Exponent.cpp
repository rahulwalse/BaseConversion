/*
	Implementation of a function to calculate x^n.
*/

int Exponent(int base, int exponent)
{
	int baseraisetoexponent = base;

	if (exponent == 0)
	{
		return 1;
	}
	else
	{
		for (int count = 1; count < exponent; count++)
		{
			baseraisetoexponent = baseraisetoexponent * base;
		}
	}
	return baseraisetoexponent;
}
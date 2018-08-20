#include <stdio.h>

struct fraction
{
	int numerator;
	int denominator;
};

int gcd(int u, int v)
{
	int t;
	while (u > 0)
	{
		if (u < v)
		{
			t = u;
			u = v;
			v = t;
		}
		u = u -v;
	}
	return v;
}

// reduce input fraction to lowest terms in-place
void reduceInPlace(struct fraction* input)
{
	int lowd = gcd(input->numerator, input->denominator);
	input->numerator /= lowd;
	input->denominator /= lowd;
}

// reduce input fraction then return result of lowest term
struct fraction reduce(const struct fraction* input)
{
	int lowd = gcd(input->numerator, input->denominator);
	
	struct fraction newFraction;
	newFraction.numerator = input->numerator / lowd;
	newFraction.denominator = input->denominator / lowd;
	return newFraction;
}

int main(int argc, char* args[])
{
	struct fraction myFraction = { 100, 25 };
	reduceInPlace(&myFraction);
	printf("reduceInPlace of 100 / 25 = %d / %d\n", myFraction.numerator, myFraction.denominator);

	// define another fraction as the previous one has result in-place already
	struct fraction myFraction2 = { 100, 25 };
	struct fraction resultFraction = reduce(&myFraction2);
	printf("reduce of 100 / 25 = %d / %d\n", resultFraction.numerator, resultFraction.denominator);
	return 0;
}

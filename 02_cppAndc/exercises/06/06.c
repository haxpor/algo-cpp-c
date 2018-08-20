#include <stdio.h>

int gcd(int u, int v) {
	int t;
	
	while (u > 0) {
		if (u < v) {
			t = u;
			u = v;
			v = t;
		}
		u = u % v;
		printf("gcd takes on %d\n", v);
	}
	return v;
}

int main(int argc, char* args[])
{
	printf("gcd(12345, 56789) = %d\n", gcd(12345, 56789));
	return 0;
}

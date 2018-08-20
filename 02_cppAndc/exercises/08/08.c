#include <stdio.h>

int _gcd(int u, int v) {
	int t;
	
	while (u > 0) {
		if (u < v) {
			t = u;
			u = v;
			v = t;
		}
		u = u % v;
	}
	return v;
}

int gcd(int u, int v, int w)
{
	return _gcd(_gcd(u, v), w);
}

int main(int argc, char* args[])
{
	printf("gcd(450, 60, 150) = %d\n", gcd(450, 60, 150));
	printf("gcd(455, 60, 150) = %d\n", gcd(455, 60, 150));

	return 0;
}

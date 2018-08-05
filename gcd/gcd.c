/**
 * gcd
 *
 * gcd computes gcd of input x, and y parameter via terminal.
 */

#include <stdio.h>

int gcd(int u, int v) {
	int t;
	while (u > 0) {
		if (u < v) {
			t = u;
			u = v;
			v = t;
		}
		u = u - v;
	}
	return v;
}

int main() {
	int x, y;
	printf("enter x: ");
	scanf("%d", &x);
	printf("enter y: ");
	scanf("%d", &y);

	if (x > 0 && y > 0) {
		printf("gcd(%d,%d) = %d\n", x, y, gcd(x,y));
	}
}

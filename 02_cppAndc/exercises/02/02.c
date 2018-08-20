#include <stdio.h>

int cr(int a, int b)
{
	return a % b;
}

int main(int argc, char* args[])
{
	printf("10 %% 2 = %d\n", cr(10, 2));
	printf("10 %% 3 = %d\n", cr(10, 3));
	printf("10 %% -2 = %d\n", cr(10, -2));
	printf("10 %% -3 = %d\n", cr(10, -3));
	printf("-10 %% 2 = %d\n", cr(-10, 2));
	printf("-10 %% 3 = %d\n", cr(-10, 3));
	printf("-10 %% -2 = %d\n", cr(-10, -2));
	printf("-10 %% -3 = %d\n", cr(-10, -3));
	return 0;
}

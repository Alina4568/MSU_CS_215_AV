#include <stdio.h>

int main(void)
{
	unsigned int xx, nn, pp, yy;
	scanf("%d %d %d %d", &xx, &nn, &pp, &yy);
	yy =~ yy;
	yy >>= (32 - nn);
	yy <<= (32 - nn - pp + 1);
	xx = xx | yy;
	printf("%d\n", xx);
	return 0;
}

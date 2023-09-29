#include <stdio.h>

int main(void)
{
    unsigned int aa;
    char c;
    int i;
    scanf("%u", &aa);
    for(int i = 1000; i > 0; i = i / 10)
    {
        c = '0' + (aa / i);
        aa %= i;
        printf("%c", c);
    }
    printf("\n");

    return 0;
}
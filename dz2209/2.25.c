#include <stdio.h>

int main(void)
{
    unsigned int aa = 0;
    char c;
    int i;
    for(int i = 0; i < 4; i++)
    {
        c = getchar();
        aa = aa * 10 + (c - '0');
    }
    printf("%u \n", aa);

    return 0;
}
#include <stdio.h>

int main(void)
{
    int i;
    char c;
    for(i=0, c=getchar(); c!=' ' && c!='\n' && c!='\t' && c!=EOF; i++, c= getchar());

    return 0;
}
#include <stdio.h>
#include <stdlib.h>


int FillStr_GetLen(char *str)
{
    char  c;
    int len = 0;
    while((c = getchar()) != '\n') {
        str[len] = c;
        len++;
        str = (char*) realloc(str, len);
    }
    str[len] = '\0';
    return len;
}

void FF(char *s, char t[])
{
    int j = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if((s[i] >= '0') && (s[i] <= '9')) 
        {
            t[j] = s[i];
            j++;
        }
    }
    for(int i = 0; s[i] != '\0'; i++)
    {
        if((s[i] < '0') || (s[i] > '9')) 
        {
            t[j] = s[i];
            j++;
        }
    }
    
    for(int i = 0; i < j; i++)
        printf("%c", t[i]);
    printf("\n");
}

int main() 
{
    char *s = NULL;
    s = (char*) malloc(sizeof(char));
    int len;
    len = FillStr_GetLen(s);
    char t[len];
    FF(s, t);
    free(s);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define N 10

void InputArr(double a[])
{
    double max = 1000, min = -1000;
    for(int i = 0; i < N; i++)
        a[i] = (double) rand() / RAND_MAX * (max - min) + min;
}

void OutputArr(double a[])
{
    for(int i = 0; i < N; i++)
        printf("%lf \n", a[i]);
}

void Change_Sign(double a[])
{
     for(int i = 0; i < N; i++)
         if(a[i] < 0) 
            a[i] = -a[i];
}

int main()
{
    double X[N];
    InputArr(X);
    OutputArr(X);
    printf("\n");
    Change_Sign(X);
    OutputArr(X);
    
    return 0;
}
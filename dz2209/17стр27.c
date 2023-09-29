
#include <stdio.h>
#include <stdlib.h>

void Print(double *arr, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%lf ", arr[i]);
    }
    printf("\n");
}

void Insert_Sort(double *arr, int n)
{
    int i, j;
    double key;
    for(j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;
        while((i > 0) && (arr[i] > key)){
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key;
    }
    Print(arr, n);
}

int main()
{
    int n, i;
    double c;
    scanf("%d", &n);
    double *arr;
    arr = malloc(n * sizeof(double));
    for(i = 0; i < n; i++)
    {
        scanf("%lf", &c);
        arr[i] = c;
    }
    
    Insert_Sort(arr, n);
    
    free(arr);
    return 0;
}

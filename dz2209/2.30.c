
#include <stdio.h>

#define N = 10

void AA()
{
    printf(" a) \n");
    printf("short %lu\n", sizeof(short));
    printf("int %lu\n", sizeof(int));
    printf("long %lu\n", sizeof(long));
    printf("float %lu\n", sizeof(float));
    printf("double %lu\n", sizeof(double));
    printf("long double %lu\n", sizeof(long double));
    printf("\n");
}

void BB()
{
    char cc = -9;
    unsigned char ss = -9;
    printf(" b) \n");
    if(cc == ss) printf("unsigned char \n");
    else printf("signed char \n");
    printf("\n");
}

void CC()
{
    printf(" c) \n");
    int a1 = 10;
	unsigned int a2 = 10u;
	long a3 = 1l;
	unsigned long a4 = 10ul;
	int a5 = 013;
	int a6 =0xB;
	float b1=2.459f;
	long double b2=999.192837l;
	float b3=19.04e+13;
	
	printf("%u \n", a1);
	printf("%u \n", a2);
	printf("%ld \n", a3);
	printf("%lu \n", a4);
	printf("%u \n", a5);
	printf("%u \n", a6);
	
	printf("%f \n", b1);
	printf("%Lf \n", b2);
	printf("%f \n", b3);
	printf("\n");
    
}

void DD()
{
    printf(" d) \n");
    if(('0' < '9') && ('a' < 'z') && ('A' < 'Z'))
        if((' ' < '0') && ('9' < 'A') && ('Z' < 'a'))
            printf("пробел, '0' - '9','A' - 'Z', 'a' - 'z'\n");
}

void GG()
{
    printf(" g) %d \n", -198 % 100);
}


int main()
{
    AA();
    BB();
    CC();
    DD();
 
    printf(" e) \n");
    int qq;
    printf("%d\n", qq); //инициализация которого явно не указана, инициализируется так, как если бы ему присваивалась константа 0

    printf(" f) выдаёт ошибку\n");
    //N = 15;
    
    GG();
    
    return 0;
}

#include <stdio.h>

int main(void)
{
    // a)
	while(E1)
	{
		if(E2)
			continue;
		S;
	}
	
	// б)
	do {
		if(E1)
			continue;
		else 
			S1;
		S2;
	} while(E2);

    return 0;
}
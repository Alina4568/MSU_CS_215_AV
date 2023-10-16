#include <stdio.h>
#include<stdlib.h>

typedef struct data 
{ 
    double f; 
    char *s[2];
} data;

typedef struct lnode 
{ 
    struct data *p; 
    struct lnode *next; 
} lnode; 

void print(lnode * list) //вывод стека
{
    for(lnode * t = list; t != NULL; t = t->next)
    {
        printf("%lf ", (t->p)->f);
        printf("%s ", *((t->p)->s));
    }
    printf("\n");
}

void push(lnode ** plist, data * d) //добавление элемента в начало стека
{
    lnode * t = malloc(sizeof(lnode));
	t->p = d;
	t->next = *plist;
	*plist = t;
}

data pop(lnode ** plist) // удаление первого элемента стека
{
    lnode * t = *plist;
    data res = *(t->p);   
    *plist = t->next;
    free(t);
    return res;
}

int is_empty(lnode * list) //проверка на пустоту стека
{
    return list == NULL;
}

lnode * copy_list(lnode * list1) 
{
    lnode * plist = NULL, * plist2 = NULL;
	lnode * l1 = list1;
	
	while(l1 != NULL)
	{
    	push(&plist, l1->p);
		l1 = l1->next;
	}
	
	while(plist != NULL)
	{
    	push(&plist2, plist->p);
		plist = plist->next;
	}
	
	return plist2;
}



int main()
{
    data test[] = { {5.8, {"hello"}}, {7.54, {"code"}}, {90.1, {"xyz"}}};
    lnode * list1 = NULL;
    lnode * list2 = NULL;
    for(size_t i = 0; i < sizeof(test) / sizeof(test[0]); i++)
    {
        push(&list1, &test[i]);
    }

    printf("L1: ");
    print(list1);
    
    list2 = copy_list(list1);
    printf("L2: ");
    print(list2);
    
    return 0;
}

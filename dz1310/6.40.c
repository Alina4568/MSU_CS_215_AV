#include <stdio.h>
#include<stdlib.h>

typedef char Data;
typedef struct Node Node;

struct Node 
{
    Data * data;
    Node * next;
};

void print(Node * list);
void push(Node ** plist, Data * d);
Data pop(Node ** plist);
int is_empty(Node * list);

void push(Node ** plist, Data * d) //добавление элемента в конец списка
{
    Node * p = malloc(sizeof(Node));
	p->data = d;
	p->next = *plist;
	*plist = p;
}

void print(Node * list) //вывод списка
{
    for(Node * p = list; p != NULL; p = p->next){
        printf("%c", *(p->data));}
    printf("\n");
}

Data pop(Node ** plist) // удаление последнего элемента стека
{
    Node * p = *plist;
    Data res = *(p->data);   
    *plist = p->next;
    free(p);
    return res;
}


int is_empty(Node * list) //проверка на пустоту списка
{
    return list == NULL;
}


int contain(Node * list, Data d) // 1 - есть, 0 - нет
{
    Node * p = list;
	while (p != NULL) 
	{
		if (*(p->data) == d) 
		    return 1;
		p = p->next;
	}
	return 0;
}


Node * new_list(Node * list1, Node * list2) 
{
    Node * plist = NULL;
	Node * l1 = list1, *l2 = list2;
	char * c;
	while(l1 != NULL)
	{
	    c = l1->data;
		if (contain(l2, *c) == 0) 
    		push(&plist, c);
		l1 = l1->next;
	}
	l1 = list1;
	l2 = list2;
	while(l2 != NULL)
	{
	    c = l2->data;
		if (contain(l1, *c) == 0) 
    		push(&plist, c);
		l2 = l2->next;
	}
	
	return plist;
}


int main()
{
    char test1[] = "edcpa";
    char test2[] = "wcdkja";
    Node * list1 = NULL, * list2 = NULL, * list3 = NULL;
    
    //printf("Empty: %s\n", is_empty(list) ? "YES": "NO");
    for(size_t i = 0; i < sizeof(test1) / sizeof(test1[0]); i++)
    {
        push(&list1, &test1[i]);
    }
    for(size_t i = 0; i < sizeof(test2) / sizeof(test2[0]); i++)
    {
        push(&list2, &test2[i]);
    }

    print(list1);
    print(list2);
    
    printf("..................\n");
    list3 = new_list(list1, list2);
    print(list3);
    
    
    while(!is_empty(list1)){
        char d = pop(&list1);}
    while(!is_empty(list2)){
        char d = pop(&list2);}
    while(!is_empty(list3)){
        char d = pop(&list3);}
    printf("Empty 1: %s\n", is_empty(list1) ? "YES": "NO");
    printf("Empty 2: %s\n", is_empty(list2) ? "YES": "NO");
    printf("Empty 3: %s\n", is_empty(list3) ? "YES": "NO");
    
    return 0;
}

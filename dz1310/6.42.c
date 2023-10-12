#include <stdio.h>
#include<stdlib.h>

typedef int Data;
typedef struct Node Node;

struct Node 
{
    Data data;
    Node * next;
};

void print(Node * list) //вывод очереди
{
    for(Node * p = list; p != NULL; p = p->next){
        printf("%d ", p->data);}
    printf("\n");
}

void push(Node ** plist, Data d) //добавление элемента в начало очереди
{
    Node * p = malloc(sizeof(Node));
	p->data = d;
	p->next = *plist;
	*plist = p;
}

Data pop(Node ** plist) // удаление последнего элемента очереди
{
    Node * p = *plist;
    Node * pp = p;
    Data res;
    if(p != NULL)
    {
        if(p->next != NULL)
        {
            while(p->next != NULL)
            {
                pp = p;
                p = p->next;
            }
            pp->next = NULL;
        }
        else 
            *plist = NULL;
        res = p->data;
        free(p);
        return res;
    }
}

int is_empty(Node * list) //проверка на пустой очереди
{
    return list == NULL;
}

int main()
{
    Data test[] = {15, 38, 22, 9, 1};
    Node * list = NULL;

    for(size_t i = 0; i < sizeof(test) / sizeof(test[0]); i++)
    {
        push(&list, test[i]);
        printf("push %d:", test[i]);
        print(list);
    }
	
	printf("\n");
	print(list);
	printf("\n");
	
    while(!is_empty(list)){
        Data d = pop(&list);
        printf("pop %d:", d);
        print(list);
    }
    printf("Empty: %s\n", is_empty(list) ? "YES": "NO");

    return 0;
}

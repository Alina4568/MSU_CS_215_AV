#include <stdio.h>
#include<stdlib.h>

typedef double Data;
typedef struct Node Node;

struct Node 
{
    Data * data;
    Node * next;
};


void push(Node ** plist, Data * d) //добавление элемента в конец списка
{
    Node * p = malloc(sizeof(Node));
	p->data = d;
	p->next = *plist;
	*plist = p;
}

void pop(Node ** plist) // удаление последнегостека элемента стека
{
    Node * p = *plist;
    *plist = p->next;
    free(p);
}

void print(Node * list) //вывод списка
{
    for(Node * p = list; p != NULL; p = p->next){
        printf("%f ", *(p->data));}
    printf("\n");
}

void change_first_last(Node * list) // a) меняет местами первый и последний элементы списка;
{
    Node * p = list;
    Data * t;
    if(p != NULL)
    {
        t = list->data;
        while(p->next != NULL)
        {
            p = p->next;
        }
        list->data = p->data;
        p->data = t;
    }
}

void delete_first_occurrence(Node ** plist, Data nn) // b) удаляет из списка первое вхождение элемента с заданным значением (если оно есть); 
{
    Node * p = *plist;
    Node * p2 = p;
    int flag = 1;
    if(p != NULL)
    {
        while(flag && (p->next != NULL))
        {
            if(*(p->data) == nn)
            {
                flag = 0;
                if(p == *plist) //если первый элемент
                {
                    *plist = p->next;
                }
                else
                {
                    p2->next = p->next;
                }
            }
            p2 = p;
            p = p->next;
        }
        
        if(flag && (*(p->data) == nn)) // если последний 
        {
            if(p == *plist) //если первый элемент
            {
                *plist = NULL;
            }
            else
            {
                p2->next = NULL;
            }
        }
    }
    
}

void delete_all_occurrences(Node ** plist, Data nn) //c) удаляет из списка все вхождения элемента с заданным значением (если они есть); 
{
    Node * p = *plist;
    Node * p2 = p;
    if(p != NULL)
    {
        while(p->next != NULL)
        {
            if(*(p->data) == nn)
            {
                if(p == *plist) //если первый элемент
                {
                    *plist = p->next;
                }
                else
                {
                    p2->next = p->next;
                }
            }
            else
                p2 = p;
            p = p->next;
        }
        
        if(*(p->data) == nn) // если последний 
        {
            if(p == *plist) //если первый элемент
            {
                *plist = NULL;
            }
            else
            {
                p2->next = NULL;
            }
        }
    }
}

void add(Node * p, Data nn)
{
    Node * t = malloc(sizeof(Node)); 
    t->data = p->data;
    
    t->next = p->next;
    p->next = t;
}


void add_link(Node * list, Data nn) //d) после каждого звена с заданным значением вставляет еще одно звено с таким же значением. 
{
    Node * p = list;
    
    if(p != NULL)
    {
        while(p->next != NULL)
        {
            if(*(p->data) == nn)
            {
                add(p, nn);
                p = p->next;
            }
            p = p->next;
        }
        
        if((*(p->data) == nn) && (p->next == NULL)) // последнее звено
        {
            add(p, nn);
        }
    }
}


int main()
{
    Data test[] = {15, 3, 1, 18, 15, 15};
    Node * list = NULL;

    for(size_t i = 0; i < sizeof(test) / sizeof(test[0]); i++)
    {
        push(&list, &test[i]);
    }
    
    print(list);
    
    //change_first_last(list); // a) меняет местами первый и последний элементы списка;
    
    //delete_first_occurrence(&list, 14); // b) удаляет из списка первое вхождение элемента с заданным значением (если оно есть); 
    
    //delete_all_occurrences(&list, 15); //c) удаляет из списка все вхождения элемента с заданным значением (если они есть); 
    
    //add_link(list, 15); //d) после каждого звена с заданным значением вставляет еще одно звено с таким же значением. 
    
    print(list);
    
    while(list != NULL){
        pop(&list);
    }
    
    return 0;
}

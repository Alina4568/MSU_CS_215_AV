#include <stdio.h>
#include<stdlib.h>

typedef double Data;
typedef struct Node Node;

struct Node 
{
    Data * data;
    Node * next;
};


void push(Node ** plist, Data * d) //добавление элемента в начало списка
{
    Node * p = malloc(sizeof(Node));
	p->data = d;
	p->next = *plist;
	*plist = p;
}

Data pop(Node ** plist) // удаление последнегостека элемента стека
{
    Node * p = *plist;
    Data res = *(p->data);   
    *plist = p->next;
    free(p);
    return res;
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
    while(flag && (p != NULL))
    {
        if(*(p->data) == nn)
        {
            flag = 0;
            if(p == *plist) //если первый элемент
            {
                *plist = p->next;
                free(p);
            }
            else
            {
                p2->next = p->next;
                free(p);
            }
        }
        p2 = p;
        p = p->next;
    }
    
}

void delete_all_occurrences(Node ** plist, Data nn) //c) удаляет из списка все вхождения элемента с заданным значением (если они есть); 
{
    Node * p = *plist;
    Node * p2 = p;
    while(p != NULL)
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
    
    while(p != NULL)
    {
        if(*(p->data) == nn)
        {
            add(p, nn);
            p = p->next;
        }
        p = p->next;
    }
        
}

int is_empty(Node * list) //проверка на пустоту списка
{
    return list == NULL;
}


int main()
{
    Data test[] = {15, 3, 1, 14, 15, 15};
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
    
    while(!is_empty(list)){
        Data d = pop(&list);
    }
    printf("Empty: %s\n", is_empty(list) ? "YES": "NO");
    
    return 0;
}

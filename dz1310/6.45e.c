#include <stdio.h>
#include<stdlib.h>

typedef int Data;
typedef struct Node Node;

struct Node 
{
    Data data;
    Node * left;
    Node * right;
};

void print(Node *tree) {
    if (tree!=NULL) 
    {
        printf("%d\n", tree->data); //корень дерева
        print(tree->left); //Рекурсивная функция для левого поддерева
        print(tree->right); //Рекурсивная функция для правого поддерева
    }
}

Node * add_node(Node *tree, Data d) {
    if (tree == NULL) // Если дерева нет, то формируем корень
    { 
        tree = malloc(sizeof(Node));
        tree->data = d;  
        tree->left =  NULL;
        tree->right = NULL; 
    }
    else  if (d < tree->data)   // добавление в левое поддерево
        tree->left = add_node(tree->left, d);
    else    // добавление в правое поддерево
        tree->right = add_node(tree->right, d);
    return(tree);
}

void delete(Node *tree) //удаление поддерева
{
    if(tree != NULL) 
    {
        delete(tree->left);
        delete(tree->right);
        tree = NULL;
        free(tree);
    }
}

int is_empty(Node * tree) //проверка на пустоту списка
{
    return tree == NULL;
}


Data number_of_nodes(Node * tree, Data n)
{
    int kol = 0;
    
    if(tree == NULL)
        return 0;
    
    else if(n == 0)
        return 1;
    
    else
    {
        kol += number_of_nodes(tree->left, n-1);
		kol += number_of_nodes(tree->right, n-1);
    }
    
    return kol;
}

int main()
{
    Node * tree = NULL;
    Data test[] = {5,2,8,7,2,9,1,5};
    Node * list = NULL;
    int kol = 0;
    int N = 2; // уровень дерева

    for(size_t i = 0; i < sizeof(test) / sizeof(test[0]); i++)
    {
        tree = add_node(tree, test[i]);
    }
    print(tree);
    
    printf("..............\n");
    
    kol = number_of_nodes(tree, N);
    printf("На %d уровне %d узлов\n", N, kol);

    delete(tree);
    printf("\nEmpty: %s\n", is_empty(list) ? "YES": "NO");
    
    return 0;
}

/*      
        5
    2       8
  1   2   7   9
         5   
*/
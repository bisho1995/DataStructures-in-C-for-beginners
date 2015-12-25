#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
int main()
{
    struct Node
    {
        int data;
        struct Node * left,* right;
        int h; //height of the tree
    };

    typedef struct Node  node;

    node *root;

    int height(node * ptr)
    {

    }

    void add(int data)
    {
        node * tmp=malloc(sizeof(node));
        tmp->right=NULL;
        tmp->left=Null;
        tmp->data=0;
        tmp->height=0;

    }

    return 0;
}

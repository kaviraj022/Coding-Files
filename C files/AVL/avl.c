#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "AVL.h"
int main()
{
    AVL* a = createAVL();
    a->root = insertNode(a->root,100);
    a->len++;
    a->root = insertNode(a->root,80);
    a->len++;
    a->root = insertNode(a->root,60);
    a->len++;
    a->root = insertNode(a->root,40);
    a->len++;
    a->root = insertNode(a->root,20);
    a->len++;
    a->root = insertNode(a->root,10);
    a->len++;
    level_order(a);
}
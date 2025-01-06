#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "LinkedList.h"
#include "StackAL.h"
bool is_operator(char ch)
{
    return ch == '^' || ch == '/' || ch=='*' || ch=='+' 
                || ch=='-' || ch=='(' || ch==')';
}
void postfix_to_infix(char postfix[], char infix[])
{
    StackL* st = createStackL();
    for(int i=0;postfix[i]!='\0';i++)
    {
        if(!is_operator(postfix[i]))
        {
            LinkedList* LL = createLinkedList();
            insertNewNodeInLL(LL,postfix[i]);
            pushL(st,LL);
        }
        else
        {
            LinkedList* LL2 = popL(st);
            LinkedList* LL1 = popL(st);
            insertNewNodeInLL(LL1,postfix[i]);
            LL1->lastNode->next = LL2->headNode;
            LL1->lastNode = LL2->lastNode;
            LL1->len = LL1->len + LL2->len;
            insertNodeAtPos(LL1,'(',0);
            insertNewNodeInLL(LL1,')');
            pushL(st,LL1);
        }
    }
    int i=0;
    Node* curr = peekL(st)->headNode;
    while(curr!=NULL)
    {
        infix[i++] = curr->data;
        curr = curr->next;
    }
    infix[i]='\0';
}
int main()
{
    char postfix[1000],infix[1000];
    scanf("%s",postfix);
    postfix_to_infix(postfix,infix);
    printf("%s",infix);
}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "LinkedList.h"
#include "StackAL.h"
bool is_operator(char ch)
{
    return ch == '^' || ch == '/' || ch=='*' || ch=='+' 
                || ch=='-' || ch=='(' || ch==')';
}
void prefix_to_infix(char prefix[], char infix[])
{
    StackL* st = createStackL();
    int n = strlen(prefix);
    for(int i=n-1;i>=0;i--)
    {
        if(!is_operator(prefix[i]))
        {
            LinkedList* LL = createLinkedList();
            insertNewNodeInLL(LL,prefix[i]);
            pushL(st,LL);
        }
        else
        {
            LinkedList* LL1 = popL(st);
            LinkedList* LL2 = popL(st);
            insertNewNodeInLL(LL1,prefix[i]);
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
    char prefix[1000],infix[1000];
    scanf("%s",prefix);
    prefix_to_infix(prefix,infix);
    printf("%s",infix);
}
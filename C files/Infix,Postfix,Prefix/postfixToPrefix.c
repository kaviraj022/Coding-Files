#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "StackA.h"
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
int precedence(char ch)
{
    switch(ch)
    {
        case '^': return 3;
        case '/': return 2;
        case '*': return 2;
        case '+': return 1;
        case '-': return 1;
        default: return 0;
    }
}
void reverse(char str[], int s, int e)
{
    if(s<e)
    {
        char t = str[s];
        str[s] = str[e];
        str[e] = t;
        reverse(str,s+1,e-1);
    }
}
void infix_to_prefix(char infix[], char prefix[])
{
    int k = 0,n = strlen(infix);
    Stack* st = createStack();
    for(int i=n-1;i>=0;i--)
    {
        if(!is_operator(infix[i]))
            prefix[k++] = infix[i];
        else
        {
            if(infix[i]==')')
                push(st,infix[i]);
            else if(infix[i]=='(')
            {
                while(peek(st)!=')')
                    prefix[k++] = pop(st);
                pop(st);
            }
            else
            {
                while(!isEmpty(st) && precedence(infix[i]) < precedence(peek(st)))
                    prefix[k++] = pop(st);
                push(st,infix[i]);
            }
        }
    }
    while(!isEmpty(st))
        prefix[k++] = pop(st);
    prefix[k] = '\0';
    reverse(prefix,0,k-1);
}
void postfix_to_prefix(char postfix[],char prefix[])
{
    char infix[1000];
    postfix_to_infix(postfix,infix);
    infix_to_prefix(infix,prefix);
}
int main()
{
    char postfix[1000],prefix[1000];
    scanf("%s",postfix);
    postfix_to_prefix(postfix,prefix);
    printf("%s",prefix);
}
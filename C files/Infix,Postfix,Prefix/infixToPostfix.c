#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "StackA.h"
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
bool is_operator(char ch)
{
    return ch == '^' || ch == '/' || ch=='*' || ch=='+' 
                || ch=='-' || ch=='(' || ch==')';
}
void infix_to_postfix(char infix[], char postfix[])
{
    int k = 0;
    Stack* st = createStack();
    for(int i=0;infix[i]!='\0';i++)
    {
        if(!is_operator(infix[i]))
            postfix[k++] = infix[i];
        else
        {
            if(infix[i]=='(')
                push(st,infix[i]);
            else if(infix[i]==')')
            {
                while(peek(st)!='(')
                    postfix[k++] = pop(st);
                pop(st);
            }
            else
            {
                while(!isEmpty(st) && precedence(infix[i]) <= precedence(peek(st)))
                    postfix[k++] = pop(st);
                push(st,infix[i]);
            }
        }
    }
    while(!isEmpty(st))
        postfix[k++] = pop(st);
    postfix[k] = '\0';
}
int main()
{
    char infix[1000],postfix[1000];
    scanf("%s",infix);
    infix_to_postfix(infix,postfix);
    printf("%s\n",postfix);

}
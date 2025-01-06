#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
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
int main()
{
    char infix[1000],prefix[1000];
    scanf("%s",infix);
    infix_to_prefix(infix,prefix);
    printf("%s\n",prefix);

}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct _node
{
    char ch;
    int freq;
    struct _node* left;
    struct _node* right;
} Node;
Node* createNode(char ch, int freq)
{
    Node* nd = (Node*)malloc(sizeof(Node));
    nd->ch = ch;
    nd->freq = freq;
    nd->left = nd->right = NULL;
    return nd;
}
#include "minBHeapN.h"
void printCode(Node* root, int code[], int k)
{
    if(root->left==NULL && root->right==NULL)
    {
        printf("%c : ",root->ch);
        for(int i=0;i<k;i++)
            printf("%d",code[i]);
        printf("\n");
        return;
    }
    code[k] = 0;
    printCode(root->left,code,k+1);
    code[k] = 1;
    printCode(root->right, code, k+1);
}
void huffmanTree(BHeap* bh)
{
    while(bh->length>1)
    {
        Node* a = extractMin(bh);
        Node* b = extractMin(bh);
        Node* c = createNode('-',a->freq+b->freq);
        c->left = a;
        c->right = b;
        addElementMinBH(bh, c);
    }
    Node* root = bh->h[0];
    int code[8];
    printCode(root,code,0);
}
int main()
{
    char message[100];
    scanf("%s",message);
    int frequency[256]={0};
    int N = 0;
    for(int i=0;message[i]!='\0';i++)
    {
        if(frequency[message[i]]==0)
            N++;
        frequency[message[i]]++;
    }
    BHeap* bh = createBHeap(N);
    int j = 0;
    for(int i=0;i<256;i++)
    {
        if(frequency[i]!=0)
        {
            Node* nd = createNode(i,frequency[i]);
            bh->h[j++] = nd;
            bh->length++;
        }
    }
    heapifyMin(bh);
    huffmanTree(bh);
}
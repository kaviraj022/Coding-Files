#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "minBHeap.h"
int minCost(BHeap* bh)
{
    int min = 0;
    while(bh->length>1)
    {
        int a = extractMin(bh);
        int b = extractMin(bh);
        min += (a+b);
        addElementMinBH(bh,a+b);
    }
    return min;
}
int main()
{
    int N;
    scanf("%d",&N);
    BHeap* bh = createBHeap(N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&bh->h[i]);
        bh->length++;
    }
    heapifyMin(bh);
    int ans = minCost(bh);
    printf("%d",ans);
}
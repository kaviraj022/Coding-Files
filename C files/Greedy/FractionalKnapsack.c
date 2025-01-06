#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct _object
{
    float profit;
    float weight;
    float p_w;
} Object;
int cmpfunc(const void* a, const void* b)
{
    Object* p = (Object*)a;
    Object* q = (Object*)b;
    return ceil(q->p_w - p->p_w);
}
float maxProfit(Object obj[], int N, int M)
{
    float max = 0;
    for(int i=0;i<N;i++){
        Object x = obj[i];
        if(x.weight<=M){
            max += x.profit;
            M -= x.weight;
        }
        else{
            max += M/x.weight * x.profit;
            break;
        }
    }
    return max;
}
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    Object obj[N];
    for(int i=0;i<N;i++)
    {
        scanf("%f %f",&obj[i].profit,&obj[i].weight);
        obj[i].p_w = obj[i].profit / obj[i].weight;
    }
    qsort(obj,N,sizeof(Object),cmpfunc);
    float ans = maxProfit(obj,N,M);
    printf("%f",ans);
}
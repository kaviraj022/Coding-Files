#include<stdio.h>
#include<stdlib.h>
typedef struct _job
{
    int id;
    int profit;
    int deadline;
} Job;
int cmpfunc(const void* a, const void* b)
{
    Job* j1 = (Job*)a;
    Job* j2 = (Job*)b;
    return j2->profit - j1->profit;
}
int maxProfit(Job jobs[], int N, int M)
{
    int slots[M];
    for(int i=0;i<M;i++)
        slots[i] = -1;
    int max = 0;
    for(int i=0;i<N;i++)
    {
        Job x = jobs[i];
        for(int j=x.deadline-1;j>=0;j--)
        {
            if(slots[j]==-1)
            {
                slots[j] = x.id;
                max += x.profit;
                break;
            }
        }
    }
    return max;
}
int main()
{
    int N,M=0;
    scanf("%d",&N);
    Job jobs[N];
    for(int i=0;i<N;i++)
    {
        jobs[i].id = i+1;
        scanf("%d %d",&jobs[i].profit,&jobs[i].deadline);
        if(jobs[i].deadline>M)
            M = jobs[i].deadline;
    }
    qsort(jobs,N,sizeof(Job),cmpfunc);
    int ans = maxProfit(jobs,N,M);
    printf("%d",ans);
}
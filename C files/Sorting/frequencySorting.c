#include<stdio.h>
typedef struct _ele
{
    int val;
    int freq;
} Element;
int findPivot(Element arr[], int s, int e)
{
    int idx = e;
    int i = s, j = s;
    while(i<e)
    {
        if(arr[i].freq<arr[idx].freq || (arr[i].freq==arr[idx].freq && arr[i].val < arr[idx].val))
        {
            Element t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            j++;
        }
        
        i++;
    }
    Element t = arr[idx];
    arr[idx] = arr[j];
    arr[j] = t;
    return j;
}
void quickSort(Element arr[], int s, int e)
{
    if(s<e)
    {
        int m = findPivot(arr,s,e);
        quickSort(arr,s,m-1);
        quickSort(arr,m+1,e);
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    Element elmt[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&elmt[i].val);
        elmt[i].freq = 0;
        for(int j=0;j<=i;j++)
        {
            if(elmt[j].val == elmt[i].val)
            {
                elmt[j].freq++;
                break;
            }
        }
    }
    quickSort(elmt,0,N-1);
    for(int i=N-1;i>=0;i--)
    {
        for(int j=1;j<=elmt[i].freq;j++)
            printf("%d ",elmt[i].val);
    }
}
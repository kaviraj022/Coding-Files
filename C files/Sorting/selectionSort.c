#include<stdio.h>
void selection_sort(int arr[], int N)
{
    for(int i=0;i<N-1;i++){
        int min_idx = i;
        for(int j=i+1;j<N;j++){
            if(arr[j]<arr[min_idx])
                min_idx = j;
        }
        int t = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = t;
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    selection_sort(arr,N);
    for(int i=0;i<N;i++)
        printf("%d ",arr[i]);

}
#include<stdio.h>
void insertion_sort(int arr[], int N)
{
    for(int i=1;i<N;i++) {
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && temp<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    insertion_sort(arr,N);
    for(int i=0;i<N;i++)
        printf("%d ",arr[i]);

}
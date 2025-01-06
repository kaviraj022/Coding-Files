#include<stdio.h>
int binary_search(int arr[], int left, int right, int target) 
{
    if(left>right)
        return -1;
    int mid = (left+right)/2;
    if(arr[mid]==target)
        return mid;
    if(target>arr[mid])
        return binary_search(arr,mid+1,right,target);
    return binary_search(arr,left,mid-1,target);
}
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    int key;
    scanf("%d",&key);
    int ind = binary_search(arr,0,N-1,key);
    ind==-1?printf("%d is not found",key):printf("%d id found at index %d",key,ind);
}
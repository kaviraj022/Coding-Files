#include<stdio.h>
void printSubset(int arr[], int S[], int N, int i, int k,int r)
{
  if(i==N){
    if(k==r)
    {
    for(int j=0;j<k;j++)
      printf("%d ",S[j]);
    printf("\n");
    }
  }
  else{
    S[k]=arr[i];
    printSubset(arr, S, N, i+1, k+1);
    printSubset(arr, S, N, i+1, k);
  }
}
int main()
{
  int N;
  scanf("%d",&N);
  int arr[N],S[N];
  for(int i=0;i<N;i++)
    scanf("%d",&arr[i]);
  int R;
  scanf("%d",&R);
  printSubset(arr, S, N, 0, 0,R);
}
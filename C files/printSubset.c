#include<stdio.h>
void printSubset(int arr[], int S[], int N, int i, int k)
{
  if(i==N){
    for(int j=0;j<k;j++)
      printf("%d ",S[j]);
    printf("\n");
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
  printSubset(arr, S, N, 0, 0);
  
}
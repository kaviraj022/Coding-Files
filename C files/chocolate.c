#include <limits.h>
#include <stdio.h>
int g_min = INT_MAX;
void minDifferenceSubset(int arr[], int N, int i, int k, int r, int min, int max) {
  if (i == N) {
    if (k == r) {
      if(max-min<g_min)
        g_min = max-min;
    }
  } else {
    int t_min=min,t_max=max;
    if(arr[i]<min)
      t_min = arr[i];
    if(arr[i]>max)
      t_max = arr[i];
    minDifferenceSubset(arr, N, i + 1, k + 1,r, t_min, t_max);
    minDifferenceSubset(arr, N, i + 1, k,r,min,max);
  }
}
int main() {
  int N;
  scanf("%d", &N);
  int arr[N];
  for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);
  int M;
  scanf("%d", &M);
  minDifferenceSubset(arr, N, 0, 0, M, INT_MAX, INT_MIN);
  printf("%d",g_min);
}
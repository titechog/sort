#include <stdio.h>

// フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
  int i, j, s, l, pivot;

// 先頭の要素をピボットとする
    int w = n/2;
    pivot = A[w];
  for(i = j = 1; i < n; i++){
    if(A[i] < pivot){
      int z = A[j];
      A[j] = A[i];
      A[i] = z;
      j++;
    }
  }
    for(s = l = n-1; s > j; s--){
        if(A[s] > pivot){
        int x = A[l];
        A[l] = A[s];
        A[s] = x;
        l--;
        }
    }

  if(j == k) return pivot;
  else if(j < k+1 && l >= k+1) return pivot;
    else if(j < k+1) return quick_select(A+l+1, n-l-1, k-l-1);
  else return quick_select(A+1, j-1, k);
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}

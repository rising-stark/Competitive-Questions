#include <stdio.h>
#include <iostream>
#define MAX 1001

int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}
int e(int arr[][MAX], int x, int y, int m, int n){
	if(x<0 || y<0 || x>=m || y>=n){
		return 0;
	}
	return arr[x][y];
}

int main(void) {
	int t;
	scanf("%d", &t);
	while(t--){
		int i,j,m,n;
		scanf("%d %d", &m, &n);
		int arr[m][MAX];
		for(i=0;i<m;i++){
			for(j=0;j<n;j++)
				scanf("%d", &arr[i][j]);
		}
		for(i=1;i<m;i++){
			for(j=0;j<n;j++){
				arr[i][j]+=max(e(arr, i-1, j, m, n), max(e(arr, i-1, j+1, m, n),e(arr, i-1, j-1, m, n)));
			}
		}
		int ma=0;
		for(i=0;i<n;i++){
			ma=max(ma, arr[m-1][i]);
		}
		printf("%d\n", ma);
	}
	return 0;
}
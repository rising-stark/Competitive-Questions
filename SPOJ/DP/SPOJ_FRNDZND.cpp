// https://www.spoj.com/problems/FRNDZND/

#include <stdio.h>

int main() {
	int n,q,i;
	scanf("%d %d", &n, &q);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	for(i=0;i<q;i++){
		int l,r,ans=0;
		scanf("%d %d", &l, &r);
		if(r==l){
			ans=arr[l-1];
		}
		printf("%d\n",ans);
	}
	return 0;
}

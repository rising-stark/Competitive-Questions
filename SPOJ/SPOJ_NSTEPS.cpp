#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	while(n--){
		int x,y,ans=-1;
		scanf("%d %d", &x, &y);
		if(x>=0 && x==y){
			if(x&1){
				ans=2*x-1;
			}else{
				ans=2*x;
			}
		}else if(x>=2 && (x-2)==y){
			if(x&1){
				ans=2*x-3;
			}else{
				ans=2*x-2;
			}
		}
		if(ans==-1){
			printf("No Number\n");
		}else{
			printf("%d\n", ans);
		}
	}
	return 0;
}
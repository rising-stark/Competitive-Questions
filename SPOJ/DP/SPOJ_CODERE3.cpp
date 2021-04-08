#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int i,j,n;
		cin>>n;
		int arr[n];
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		int dp[2][n];
		
		for(i=0;i<2;i++){
			for(j=0;j<n;j++){
				dp[i][j]=1;
			}
		}
		for(i=1;i<n;i++){
			for(j=0;j<i;j++){
				if(arr[i]>arr[j]){
					dp[0][i]=max(dp[0][i], dp[0][j]+1);
				}
			}
		}
		for(i=n-2;i>=0;i--){
			for(j=n-1;j>i;j--){
				if(arr[i]>arr[j]){
					dp[1][i]=max(dp[1][i], dp[1][j]+1);
				}
			}
		}
		/*for(i=0;i<2;i++){
			for(j=0;j<n;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}*/
		int ma=-1;
		for(i=0;i<n;i++){
			ma=max(ma, dp[0][i]+dp[1][i]-1);
		}
		cout<<ma<<endl;
	}
	return 0;
}
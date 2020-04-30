#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int i,j,n,m;
		cin>>n>>m;
		int arr[n][n];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		//This dp matrix stores the minimun of max-up height at a time in index 0 of third dimension
		//This dp matrix stores the total minimum time taken in index 1 of third dimension
		int dp[n][n][2];
		dp[0][0][0]=arr[0][0];
		dp[0][0][1]=arr[0][0];
		
		// Initializing the 0th row.
		for(i=1;i<n;i++){
			dp[0][i][1]=dp[0][i-1][1]+abs(arr[0][i]-arr[0][i-1]);
			dp[0][i][0]=max(dp[0][i-1][0], arr[0][i]-arr[0][i-1]);
			if(arr[0][i]<=arr[0][i-1]){
				dp[0][i][0]=dp[0][i-1][0];
			}else if(arr[0][i]>arr[0][i-1]){
				
			}
		}
		// Initializing the 0th column.
		for(i=1;i<n;i++){
			dp[i][0][1]=dp[i-1][0][1]+abs(arr[i][0]-arr[i-1][0]);
			if(arr[i][0]<=arr[i-1][0]){
				dp[i][0][0]=dp[i-1][0][0];
			}else if(arr[i][0]>arr[i-1][0]){
				dp[i][0][0]=max(dp[i-1][0][0], arr[i][0]-arr[i-1][0]);	
			}
		}
		for(i=1;i<n;i++){
			for(j=1;j<n;j++){
				int a,b,x,y;
				x=arr[i][j]-arr[i-1][j];
				y=arr[i][j]-arr[i][j-1];
				a=max(x, dp[i-1][j][0]);
				b=max(y, dp[i][j-1][0]);
				if(a==b){
					dp[i][j][0]=a;
					dp[i][j][1]=min(dp[i-1][j][1] + abs(x), dp[i][j-1][1]+ abs(y));
				}else if(a>b){
					dp[i][j][0]=b;
					dp[i][j][1]=dp[i][j-1][1] + abs(y);
				}else{
					dp[i][j][0]=a;
					dp[i][j][1]=dp[i-1][j][1]+ abs(x);
				}
			}
		}
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<dp[i][j][0]<<"/"<<dp[i][j][1]<<" ";
			}cout<<endl;
		}cout<<endl;
		
		if((m-dp[n-1][n-1][1]) <=0){
			cout<<"N0"<<endl;
		}else{
			cout<<"YES : "<<dp[n-1][n-1][0]<<" "<<(m-dp[n-1][n-1][1])<<endl;
		}
	}
	return 0;
}










/*

int main() {
	int t;
	cin>>t;
	while(t--){
		int i,j,n,m;
		cin>>n>>m;
		int arr[n][n];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		//This dp matrix stores the minimun of max-up height at a time in index 0 of third dimension
		//This dp matrix stores the total minimum time taken in index 1 of third dimension
		int dp[n][n][2];
		dp[0][0][0]=arr[0][0];
		dp[0][0][1]=arr[0][0];
		
		// Initializing the 0th row.
		for(i=1;i<n;i++){
			dp[0][i][1]=dp[0][i-1][1]+abs(arr[0][i]-arr[0][i-1]);
			if(arr[0][i]<=arr[0][i-1]){
				dp[0][i][0]=dp[0][i-1][0];
			}else if(arr[0][i]>arr[0][i-1]){
				dp[0][i][0]=max(dp[0][i-1][0], arr[0][i]-arr[0][i-1]);	
			}
		}
		// Initializing the 0th column.
		for(i=1;i<n;i++){
			dp[i][0][1]=dp[i-1][0][1]+abs(arr[i][0]-arr[i-1][0]);
			if(arr[i][0]<=arr[i-1][0]){
				dp[i][0][0]=dp[i-1][0][0];
			}else if(arr[i][0]>arr[i-1][0]){
				dp[i][0][0]=max(dp[i-1][0][0], arr[i][0]-arr[i-1][0]);	
			}
		}
		for(i=1;i<n;i++){
			for(j=1;j<n;j++){
				int a,b,x,y;
				x=arr[i][j]-arr[i-1][j];
				y=arr[i][j]-arr[i][j-1];
				a=max(x, dp[i-1][j][0]);
				b=max(y, dp[i][j-1][0]);
				if(a==b){
					dp[i][j][0]=a;
					dp[i][j][1]=min(dp[i-1][j][1] + abs(x), dp[i][j-1][1]+ abs(y));
				}else if(a>b){
					dp[i][j][0]=b;
					dp[i][j][1]=dp[i][j-1][1] + abs(y);
				}else{
					dp[i][j][0]=a;
					dp[i][j][1]=dp[i-1][j][1]+ abs(x);
				}
			}
		}
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<dp[i][j][0]<<"/"<<dp[i][j][1]<<" ";
			}cout<<endl;
		}cout<<endl;
		
		if((m-dp[n-1][n-1][1]) <=0){
			cout<<"N0"<<endl;
		}else{
			cout<<"YES : "<<dp[n-1][n-1][0]<<" "<<(m-dp[n-1][n-1][1])<<endl;
		}
	}
	return 0;
}

*/

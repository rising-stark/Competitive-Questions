//https://www.spoj.com/problems/BAT4/

/*
Actually the problem on SPOJ is wrong, you can verify it by seeing whole lot of downvotes for it and also in its comments.
I listed the errors there as well.
1. That there are no test cases where the solution is checked for arrays of size n=1.

2. There is no test case when reaching with 0 time left is checked.
Because my wrogn solution of 0 time left prints yes and it is getting accepted.

I seriously believe that this problem could have been real gold considering the different priorities in order and meanwhile
minimizing one based only on some conditions and other constraints.
I mean the thought of setting this problem was good but then the test-cases and poor problem description ruined it.

Checkout this testcase:
1
4 100
1 10 11 12
2 10 11 12
3 10 11 12
1 2 3 4

The Correct answer according to the problem description should be
YES : 1 92
When I was submitting a solution for the above, it was WA 4 times.
Then I submitted a solution for
YES : 2 92
and it gave AC.
Bad problem. This problem accepts solution which requires you to find the minimum of maximum abs difference in heights at a time and not just up the building.

Both the below codes are iterative or bottom-up DP.
So, here down below, the first code is the one which is AC but wrong according to the problem description.
Below it is the code which should have been the solution but is WA on submission (if in future also, the problem is not edited).
The main difference in both the codes is just the difference in the former is taken as abs value while in latter,
difference is only considered for comparison when it is positive.
*/

#include <iostream>
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
			dp[0][i][0]=max(dp[0][i-1][0], abs(arr[0][i]-arr[0][i-1]));
		}
		
		// Initializing the 0th column.
		for(i=1;i<n;i++){
			dp[i][0][1]=dp[i-1][0][1]+abs(arr[i][0]-arr[i-1][0]);
			dp[i][0][0]=max(dp[i-1][0][0], abs(arr[i][0]-arr[i-1][0]));
		}
		
		for(i=1;i<n;i++){
			for(j=1;j<n;j++){
				int a,b,x,y;
				x=abs(arr[i][j]-arr[i-1][j]);
				y=abs(arr[i][j]-arr[i][j-1]);
				a=max(x, dp[i-1][j][0]);
				b=max(y, dp[i][j-1][0]);
				if(a==b){
					dp[i][j][0]=a;
					dp[i][j][1]=min(dp[i-1][j][1] + x, dp[i][j-1][1]+ y);
				}else if(a>b){
					dp[i][j][0]=b;
					dp[i][j][1]=dp[i][j-1][1] + y;
				}else{
					dp[i][j][0]=a;
					dp[i][j][1]=dp[i-1][j][1]+ x;
				}
			}
		}
		
		if((m-dp[n-1][n-1][1]) <0){
			cout<<"NO"<<endl;
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

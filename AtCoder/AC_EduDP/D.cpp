#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod=1e9+7;
ll dp[105][100005];
void solve(){
	ll n, w, i, j;
	memset(dp, 0, sizeof(dp));
	cin>>n>>w;
	int wt[n], val[n];
	for(i=0;i<n;i++){
		cin>>wt[i]>>val[i];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=w;j++){
			if(wt[i-1]<=j){
				dp[i][j]=max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][w];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
	solve();
	return 0;
}
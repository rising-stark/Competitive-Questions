#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod = 1e9+7;
const int inf = INT_MAX-100;
//int dp[100000+1];
void solve(){
	int i, n, k;
	cin>>n>>k;
	int arr[n];
	vector<int> dp(n, inf);
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	dp[0]=0;
	for(i=0;i<n;i++){
		for(int j=1;j<=k;j++){
			if(i+j <n){
				dp[i+j]=min(dp[i+j], dp[i]+abs(arr[i+j]-arr[i]));
			}
		}
	}
	cout<<dp[n-1]<<endl;
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
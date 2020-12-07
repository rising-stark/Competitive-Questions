#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif
	int t=1;
	//scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}
ll calc(int n, int i){
	ll res=(n*1LL*(n-1))/2;
	res*=(1<<i);
	return res;
}
void solve(){
	int i, j, n;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	int dp[n][32];
	memset(dp, 0, sizeof dp);
	for(i=0;i<n;i++){
		for(j=0;j<31;j++){
			dp[i][j]=(arr[i]&(1<<j))>0;
		}
	}
	//printMat(dp, n, 32);
	for(i=0;i<31;i++){
		for(j=1;j<n;j++){
			dp[j][i]+=dp[j-1][i];
		}
	}
	ll ans=0;
	for(i=0;i<31;i++){
		ans=(ans+calc(dp[n-1][i], i));
	}
	cout<<ans<<endl;
}

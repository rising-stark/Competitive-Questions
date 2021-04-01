#include<bits/stdc++.h>
#define mem memset(dp, -1, sizeof dp)
#define ll long long int

using namespace std;

int d;
ll dp[20][20];
ll recur(string &arr, int i, int t, int c=0){
	int n = (int)arr.size();
	if(i==0){
		return c;
	}
	if(dp[i][c]!=-1 && !t){
		return dp[i][c];
	}
	int lmt = t?arr[n-i]-'0':9;
	ll ans = 0;
	for(int j = 0;j<=lmt;j++){
		ans+=recur(arr, i-1, t&(j==lmt), c+(j==d));
	}
	if(!t){
		dp[i][c] = ans;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif
	mem;
	ll a, b;
	cin>>a>>b;
	while(a && b){
		for(d=1;d<=9;d++){
			string bs = to_string(b);
			ll ans = recur(bs, bs.size(), 1);
			ll ans1 = 0;
			if(a>=2){
				string as = to_string(a-1);
				ans1=recur(as, as.size(), 1);
			}
			cout<<ans-ans1<<" ";
		}cout<<endl;
		cin>>a>>b;
	}
	return 0;
}

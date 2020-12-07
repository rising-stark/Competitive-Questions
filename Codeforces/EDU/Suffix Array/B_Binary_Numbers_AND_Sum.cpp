#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod=998244353;
const int inf = (1<<30);
void solve();

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// #ifndef ONLINE_JUDGE
	// freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	// freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	// #endif
	int t=1;
	//scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}
ll binMod(ll a, ll n, ll mod){
	ll res=1;
	while(n>0){
		if(n&1){
			res=(res*a)%mod;
		}
		n>>=1;
		a=(a*a)%mod;
	}
	return res;
}
void solve(){
	ll i, j, n, m;
	cin>>n>>m;
	ll dp[m];
	string a,b;
	cin>>a>>b;
	while(n<m){
		a='0'+a;
		n++;
	}
	dp[m-1]=a[n-1]=='1';
	for(i=m-2, j=1;i>=0;i--, j++){
		if(a[i]=='1'){
			dp[i]=(dp[i+1]+binMod(2, j, mod))%mod;
		}else{
			dp[i]=dp[i+1];
		}
	}
	ll ans=0;
	for(i=0;i<m;i++){
		if(b[i]=='1'){
			ans=(ans+dp[i])%mod;
		}
	}
	cout<<ans<<endl;
}
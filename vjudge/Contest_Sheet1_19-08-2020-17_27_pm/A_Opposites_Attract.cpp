#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod=1e9+7;
const int inf = (1<<30);
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
void solve(){
	int i, j, n;
	//scanf("%d", &n);
	cin>>n;
	int freq[21];
	memset(freq, 0, sizeof(freq));
	for(i=0;i<n;i++){
		int x;
		cin>>x;
		freq[x+10]++;
	}
	ll sum=0;
	for(i=0;i<10;i++){
		sum+=freq[i]*1LL*freq[20-i];
	}
	ll x=freq[10];
	sum+=(x*1LL*(x-1))/2;
	cout<<sum<<endl;
}

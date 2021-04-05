#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define maxx(a,b,c) max(a, max(b,c))
#define minn(a,b,c) min(a, min(b,c))
using namespace std;
const int mod=1e9+7;
const int inf = (1<<30);
void solve();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	//t=1;
	while(t--){
		solve();
	}
	return 0;
}

ll mult(ll a, ll b, ll p){
	if(a==1){
		return b%p;
	}
	if(a==0){
		return 0;
	}
	if(a&1){
		return (2*mult(a/2, b, p)%p + b)%p;
	}else{
		return (2*mult(a/2, b, p))%p;
	}
}

ll modExp(ll a, ll n, ll p){
	ll res=1;
	if(n==0){
		return 1;
	}
	if(n==1){
		return a%p;
	}
	while(n>0){
		if(n&1){
			res=(mult(min(res, a), max(res, a), p))%p;
		}
		n>>=1;
		a=mult(a, a, p)%p;
	}
	return res;
}


void solve(){
	ll i, j, n;
	cin>>n;
	string no="NO";
	string yes="YES";
	if(n==1 || n==4){
		cout<<no<<endl;
		return;
	}
	if(n==2 || n==3 || n==5 || n==7 || n==11 || n==13 || n==17 || n==23){
		cout<<yes<<endl;
		return;
	}
	if(n%2==0 || n%3==0 || n%5==0){
		cout<<no<<endl;
		return;
	}

	ll s=n-1;
	while(s&1==0){
		s>>=1;
	}
	ll a=2;
	for(i=0;i<10;a++,i++){
		ll x=modExp(a, s, n);
		if(x==1 || x==(n-1)){
			continue;
		}
		int flag=0;
		while(s!=(n-1)){
			s<<=1;
			x=mult(x, x, n);
			if(x==(n-1)){
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<no<<endl;
			return;
		}
	}
	cout<<yes<<endl;
}

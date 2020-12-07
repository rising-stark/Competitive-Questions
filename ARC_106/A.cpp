#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int> >
#define vvll vector<vector<ll> >
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pis pair<int, string>
#define psi pair<string, int>
#define ALL(x) x.begin(), x.end()
#define maxx(a,b,c) max(a, max(b,c))
#define minn(a,b,c) min(a, min(b,c))
using namespace std;
const int mod=1e9+7;
const int inf = (1<<30);
void solve();

int main(){
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif*/
	int t=1;
	//scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}
void solve(){
	ll i=0, n;
	cin>>n;
	ll a=1;
	while(a>0 && n>a){
		ll p=n-a, j=0;
		int flag=1;
		while(p>1){
			if(p%5==0){
				p/=5;
				j++;
			}else{
				flag=0;
				break;
			}
		}
		//cout<<"p = "<<p<<" j = "<<j<<" a=  "<<a<<endl;
		if(flag==1){
			cout<<i<<" "<<j<<endl;
			return;
		}
		a*=3;
		i++;
	}
	cout<<-1<<endl;
}
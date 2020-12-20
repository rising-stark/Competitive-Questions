#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vi vector<ll>
#define vll vector<ll>
#define vvi vector<vector<ll> >
#define vvll vector<vector<ll> >
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define pis pair<ll, string>
#define psi pair<string, ll>
#define ALL(x) x.begin(), x.end()
#define maxx(a,b,c) max(a, max(b,c))
#define minn(a,b,c) min(a, min(b,c))
using namespace std;
const ll mod=1e9+7;
const ll inf = (1<<30);
void solve();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif
	ll t=1;
	//scanf("%d", &t);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve(){
	ll n,s,k;
	cin>>n>>s>>k;
	ll a,b,c;
	ll x0=0, y0=0, g=1;
	a=k;
	b=n;
	c=n-s;
	g = gcd(a, b, x0, y0);
    if (c % g) {
        cout<<-1<<endl;
        return;
    }
    x0 *= c / g;
    y0 *= c / g;
   // cout<<x0<<endl;
    x0=(x0%n+n)%n;
    cout<<x0<<endl;
}
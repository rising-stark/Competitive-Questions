#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define pf push_front
#define pq priority_queue
#define pqi priority_queue<int>
#define pqc priority_queue<char>
#define pqll priority_queue<ll>
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vd vector<double>
#define vll vector<ll>
#define vvi vector<vector<int> >
#define vvc vector<vector<char> >
#define vvs vector<vector<string> >
#define vvll vector<vector<ll> >
#define vvpii vector<vector<pii> >
#define vvpll vector<vector<pll> >
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define vpii vector<pair<int, int> >
#define vpll vector<pair<ll, ll> >
#define pqpii priority_queue<pii>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)a.size()
#define maxx(a, b, c) max((a), max((b), (c)))
#define minn(a, b, c) min((a), min((b), (c)))
#define dup(x) (x).resize(distance((x).begin(), unique(all(x))))
#define null nullptr
#define mem memset(dp, -1, sizeof dp)
#define mem1 memset(dp1, -1, sizeof dp1)
#define fori for(int i=0;i<n;i++)
#define forj for(int j=0;j<m;j++)
#define popcount(mask) __builtin_popcount(mask)
#define popcountLL(mask) __builtin_popcountll(mask)
#define allUpper(a) transform(all(a), a.begin(), :: toupper)
#define allLower(a) transform(all(a), a.begin(), :: tolower)
#define ce cout<<"\n";
#define w1(x) cout<<(#x)<<"="<<(x)<<" ";
#define w2(x,y) w1(x)w1(y);ce
#define w3(x,y,z) w1(x)w1(y)w1(z);ce
#define w4(x,y,z,a) w1(x)w1(y)w1(z)w1(a);ce
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define w(...) GET_MACRO(__VA_ARGS__, w4, w3, w2, w1)(__VA_ARGS__)
#define cminn(a,b,c) a=minn(a,b,c)
#define cmaxx(a,b,c) a=maxx(a,b,c)
#define bpc(i) __builtin_popcount(i)

const int maxn = 100010;
const ll mod = ((ll)1e9)+7;
const ll inf = (1LL<<50);
const double eps = (double)1e-6;
const double pi = 3.14159265358979323;

using namespace std;
void solve();
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif
	int i=0, t=1;
	//int stress = 1;
	cin>>t;
	//cout<<t<<endl;
	//generateSieve();

	int n;
	while(t--){
		//cout<<"Case "<<(++i)<<": ";
		solve();
	}
	//if(stress==1){compare();}
	return 0;
}

void solve(){
	ll i, j, n;
	cin>>n;
	ll sum = -n;
	for(i=1;i*i<=n;i++){
		if(n%i == 0){
			int a = n/i;
			sum+=i+(i != a)*a;
		}
	}
	cout<<sum;ce
}
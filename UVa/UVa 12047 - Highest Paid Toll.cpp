//#include "bits/stdc++.h"
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <iostream>
#include <istream>
#include <ostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <bitset>
#define ll long long int
#define pb push_back
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
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
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define maxx(a, b, c) max((a), max((b), (c)))
#define minn(a, b, c) min((a), min((b), (c)))
#define dup(x) (x).resize(distance((x).begin(), unique(all(x))))
#define maxn 100001
#define null nullptr
#define mem memset(dp, -1, sizeof dp)
#define mem1 memset(dp1, -1, sizeof dp1)
#define fori for(int i=0;i<n;i++)
#define forj for(int j=0;j<m;j++)
#define w(x) cout<<(#x)<<"="<<(x)<<" "
#define cmin(a, b) a=min(a,b)
#define cmax(a, b) a=max(a,b)
#define cminn(a,b,c) a=minn(a,b,c)
#define cmaxx(a,b,c) a=maxx(a,b,c)
const ll mod=((ll)1e9)+7;
const ll inf = (1LL<<50);
const double eps = (double)1e-6;
const double pi = 3.14159265358979323;

using namespace std;

template <typename T1, typename T2, typename T3>struct trio{T1 x; T2 y; T3 z; trio(){};trio(T1 _x, T2 _y, T3 _z):x(_x), y(_y), z(_z){}};
#define tri trio<int,int,int>
#define trll trio<ll,ll,ll>

//STL pair input
template<typename T1, typename T2>inline istream& operator >> (istream& os, pair<T1, T2>& t){ return os >> t.first >> t.second;}
template<typename T1, typename T2, typename T3>inline istream& operator >> (istream& os, trio<T1, T2, T3>& t){ return os >> t.x >> t.y >> t.z; }
template<typename T>inline istream &operator>>(istream &os, vector<T>& v){for(T &i:v){os>>i;}return os;}
template<typename T>inline istream &operator>>(istream &os, vector<vector<T>>& v){for(vector<T> &i : v){os>>i;}return os;}

//STL debug by print
template<typename T1, typename T2>inline ostream& operator << (ostream& os, const pair<T1, T2>& t){ return os << t.first << " " << t.second<<endl; }
template<typename T1, typename T2, typename T3>inline ostream& operator << (ostream& os, const trio<T1, T2, T3>& t){ return os << t.x << " " << t.y << " " << t.z<<endl; }
template<typename T>void printarr(T arr[], int n){for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const vector<T>& v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const vector<vector<T>>& v){for(vector<T> i : v){os<<i;}return os;}
template<typename T>inline ostream &operator<<(ostream &os,const set<T>&v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const unordered_set<T>&v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const set<T, greater<T> >&v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const multiset<T>&v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const multiset<T, greater<T> >&v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T1, typename T2>inline ostream &operator << (ostream & os,const map<T1, T2>& v){for(pair<T1, T2> i : v){os<<i;}return os<<endl;}
template<typename T1, typename T2>inline ostream &operator << (ostream & os,const unordered_map<T1, T2>& v){for(pair<T1, T2> i : v){os<<i;}return os<<endl;}
template<typename T1, typename T2>inline ostream &operator << (ostream & os,const multimap<T1, T2>& v){for(pair<T1, T2> i : v){os<<i;}return os<<endl;}
void printgraph(vi arr[], int n){for(int i=0;i<n;i++){cout<<i<<" --> ";cout<<arr[i];}cout<<endl;}
inline ll binexp(ll a, ll b, ll m){a%=m;ll res=1;while(b){if(b&1)res=(res*a)%m;a=(a*a)%m;b>>=1;}return res;}
inline string toBase(ll a,ll b=2){string s="";if(!a)return"0";while(a){s=to_string(a%b)+s;a/=b;}return s;}
inline ll digsum(ll n){ll ans=0;while(n){ans+=n%10;n/=10;}return ans;}
inline ll sq(ll a){return a*a;}
inline double dist(pii a, pii b){return sqrt(sq(a.ff-b.ff) + sq(a.ss-b.ss));}
inline bool ispow2(ll i){return i && (i & -i) == i;}
inline bool isdigit(char c){if(c>='0' && c<='9')return true;return false;}
inline bool isupper(char c){if(c>='A' && c<='Z')return true;return false;}
inline bool islower(char c){if(c>='a' && c<='z')return true;return false;}
void solve();

/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

ll binsearch(ll l, ll r, vll arr, ll x){
	ll ans=0;
	while(l<=r){
		ll m = l+((r-l)>>1);
		if(m){
			//ans=max(ans, m);
			l=m+1;
		}else{
			//ans=min(ans, m);
			r=m-1;
		}
	}
	return ans;
}
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

	while(t--){
		//cout<<"Case "<<(++i)<<": ";
		solve();
	}
	//if(stress==1){compare();}
	return 0;
}

/*
This problem requires us to find the edge that has the maximum weight but the overall cost of
any path that includes that edge is <=p (some given amount)

What we can do is that we can find the shortest path from s (source) to all other vertices.
And then also find the shortest path from t(destination) to all other vertices.
Since, the graph is directed, we need to store the reverses edges as well.
So, we store the edges with original direction in adj and reversed edges in adj1

So, this acounts for total 2 runs of dijkstra with different adjacency lists and sources.

Note: Shortest path from any arbitrary vertex v to t(destination) is equal to shortest path
from t to v.

Now what we can do is that we can take every single edge e that connects u and v, 
and check if the shortest path from s to u + shortest path from v to t
(or from t to v) + the edge weight of e <=p, then we can take this edge as one of our
potential candidates and take its maximum with a global ans.
*/

void dijkstra(vpii adj[], int src, vll &d){
	d[src] = 0;
	set<pii> s;
	s.insert({0, src});
	while(!s.empty()){
		pii temp = *s.begin();
		s.erase(*s.begin());
		if(temp.ff == inf)
			break;
		for(auto x:adj[temp.ss]){
			if(d[x.ff] > d[temp.ss] + x.ss){
				s.erase({d[x.ff], x.ff});
				d[x.ff] = d[temp.ss] + x.ss;
				s.insert({d[x.ff], x.ff});
			}
		}
	}
}

void solve(){
	ll i, j, n, m, s, t, p;
	cin>>n>>m>>s>>t>>p;
	s--;t--;
	vpii adj[n];
	vpii adj1[n];
	forj{
		int x, y, z;
		cin>>x>>y>>z;
		x--;y--;
		adj[x].pb({y, z});
		adj1[y].pb({x, z});
	}
	vll d(n, inf), d1(n, inf);
	dijkstra(adj, s, d);
	dijkstra(adj1, t, d1);

	ll ans = -inf;
	fori{
		for(auto x:adj[i]){
			if(d[i] + d1[x.ff] + x.ss <=p){
				cmax(ans, x.ss*1LL);
			}
		}
	}
	cout<<((ans==(-inf))?-1:ans)<<endl;
}
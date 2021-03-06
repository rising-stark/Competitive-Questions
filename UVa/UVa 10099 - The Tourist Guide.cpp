//#include "bits/stdc++.h"
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <istream>
#include <ostream>
#include <cstdlib>
#include <cmath>
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
const ll mod=((ll)1e9)+7;
const ll inf = (1<<30);
const double eps = (double)1e-6;
const double pi = 3.14159265358979323;

using namespace std;

template <typename T1, typename T2, typename T3>struct trio{T1 x; T2 y; T3 z; trio(){};trio(T1 _x, T2 _y, T3 _z):x(_x), y(_y), z(_z){}};
#define tri trio<int,int,int>
#define trll trio<ll,ll,ll>

//STL pair input
template<typename T1, typename T2>inline istream& operator >> (istream& os, pair<T1, T2>& t){ os >> t.first; os >> t.second; return os; }
template<typename T>inline istream &operator>>(istream &os, vector<T>& v){for(T &i:v){cin>>i;}return os;}
template<typename T>inline istream &operator>>(istream &os, vector<vector<T>>& v){for(vector<T> &i : v){cin>>i;}return os;}

//STL debug by print
template<typename T1, typename T2>inline ostream& operator << (ostream& os, const pair<T1, T2>& t){ return os << t.first << " " << t.second<<endl; }
template<typename T1, typename T2, typename T3>inline ostream& operator << (ostream& os, const trio<T1, T2, T3>& t){ return os << t.x << " " << t.y << " " << t.z<<endl; }
template<typename T>void printarr(T arr[], int n){for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const vector<T>& v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const vector<vector<T>>& v){for(vector<T> i : v){os<<i;}return os;}
template<typename T>inline ostream &operator<<(ostream &os,const set<T>&v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const set<T, greater<T> >&v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const multiset<T>&v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const multiset<T, greater<T> >&v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T1, typename T2>inline ostream &operator << (ostream & os,const map<T1, T2>& v){for(pair<T1, T2> i : v){os<<i;}return os<<endl;}
template<typename T1, typename T2>inline ostream &operator << (ostream & os,const multimap<T1, T2>& v){for(pair<T1, T2> i : v){os<<i;}return os<<endl;}
void printgraph(vi arr[], int n){for(int i=0;i<n;i++){cout<<i<<" --> ";cout<<arr[i];}cout<<endl;}
inline ll binexp(ll a, ll b, ll m){a%=m;ll res=1;while(b){if(b&1)res=(res*a)%m;a=(a*a)%m;b>>=1;}return res;}
inline string toBase(ll a,ll b=2){string s="";if(!a)return"0";while(a){s=to_string(a%b)+s;a/=b;}return s;}
inline ll digsum(ll n){ll ans=0;while(n){ans+=n%10;n/=10;}return ans;}
inline bool ispow2(ll i){return i && (i & -i) == i;}
inline bool isdigit(char c){if(c>='0' && c<='9')return true;return false;}
inline bool isupper(char c){if(c>='A' && c<='Z')return true;return false;}
inline bool islower(char c){if(c>='a' && c<='z')return true;return false;}
void solve(int, int);

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif
	int t=1;
	//int stress = 1;
	//cin>>t;
	//cout<<t<<endl;
	//generateSieve();

	ll i=0, j, n, m;
	cin>>n>>m;
	while(n && m){
		cout<<"Scenario #"<<(++i)<<endl;
		solve(n,m);
		cin>>n>>m;
	}
	//if(stress==1){compare();}
	return 0;
}

/*
I was trying to solve the problem UVa 10099 - The Tourist Guide.
At last is the Floyd-Warshall algorithm which was able to solve the problem in O(n^3).
Below is the solved the problem using this:

		Here is an easy and efficient way:

		Let MAX be the maximum edge weight in the graph.
		Binary search 0 <= k <= MAX such that you can get from A to F using only edges
		with weights >= k. You can use a breadth first search to see if this is possible
		(don't take an edge if its weight is too small).

		This gives an O((X + Y) log V) algorithm, where V is the range of your weights.

 
 with a much better time complexity of O((E + V) log MAX) where MAX is the range of weights
 in the graph.
*/
vpll adj[101];
bool bfs(ll s, ll d, ll x){
	vector<bool> vis(101, false);
	queue<pll> q;
	q.push({s, INT_MAX});
	int flag = 0;
	ll ans = 2;
	while(!q.empty()){
		pll temp = q.front();
		q.pop();
		if(temp.ff == d){
			flag=1;
			ans = max(ans, temp.ss);
			continue;
		}
		for(auto v:adj[temp.ff]){
			if(!vis[v.ff] && v.ss>=x){
				vis[v.ff]=1;
				q.push({v.ff, min(temp.ss, v.ss)});
			}
		}
	}
	return flag;
}
void solve(int n, int m){
	for(int i=0;i<=100;i++){
		adj[i].clear();
	}
	ll ans = 2;
	ll low = 0, high = 0;
	while(m--){
		ll x, y, z;
		cin>>x>>y>>z;
		x--;y--;
		adj[x].pb({y, z});
		swap(x, y);
		adj[x].pb({y, z});
		high=max(high, z);
	}
	high++;
	ll s, d, t;
	cin>>s>>d>>t;
	s--;d--;
	while(low<=high){
		ll mid = low+ ((high-low)>>1);
		bool x = bfs(s, d, mid);
		if(x){
			ans = mid;
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	ans--;
	cout<<"Minimum Number of Trips = ";
	cout<<ceil(t*1.0/ans)<<endl<<endl;
}


/*
ll binsearch(ll l, ll r, ll t, ll x){
	ll ans=r;
	while(l<=r){
		ll curtrips = l+((r-l)>>1);
		ll tripsreq = (ll)ceil((t+curtrips)*1.0/x);
		if(tripsreq>curtrips){
			//ans=max(ans, m);
			l=curtrips+1;
		}else{
			ans=min(ans, curtrips);
			r=curtrips-1;
		}
	}
	return ans;
}
void solve(int n, int m){
	ll i, j, k;
	ll dist[n+1][n+1];
	memset(dist, 0, sizeof dist);
	while(m--){
		int x, y, z;
		cin>>x>>y>>z;
		x--;y--;
		dist[x][y]=z;
		dist[y][x]=z;
	}
	ll s, d, t;
	cin>>s>>d>>t;
	s--;d--;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				dist[i][j] = max(dist[i][j], min(dist[i][k], dist[k][j]));
			}
		}
	}
	dist[s][d]--;
	cout<<"Minimum Number of Trips = ";
	//cout<<binsearch(t*1.0/dist[s][d], t, t, dist[s][d])<<endl<<endl;
	cout<<ceil(t*1.0/dist[s][d])<<endl<<endl;
}
*/
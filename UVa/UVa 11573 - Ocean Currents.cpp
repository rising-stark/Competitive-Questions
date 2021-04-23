//#include "bits/stdc++.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <bitset>
#include <istream>
#include <ostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
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
#define sz(a) (int)a.size();
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
#define ce ;cout<<"\n";
#define w1(x) cout<<(#x)<<"="<<(x)<<" "
#define w2(x,y) w1(x)w1(y)cen
#define w3(x,y,z) w1(x)w1(y)w1(z)cen
#define w4(x,y,z,a) w1(x)w1(y)w1(z)w1(a)cen
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define w(...) GET_MACRO(__VA_ARGS__, w4, w3, w2, w1)(__VA_ARGS__)
#define cmin(a, b) a=min((a), (b))
#define cmax(a, b) a=max((a), (b))
#define cminn(a,b,c) a=minn(a,b,c)
#define cmaxx(a,b,c) a=maxx(a,b,c)

const int maxn = 100010;
const ll mod = ((ll)1e9)+7;
const ll inf = (1LL<<50);
const double eps = (double)1e-6;
const double pi = 3.14159265358979323;

using namespace std;
template <typename T1, typename T2, typename T3>
struct trio{T1 x; T2 y; T3 z; trio(){};trio(T1 _x, T2 _y, T3 _z):x(_x), y(_y), z(_z){}};
#define tri trio<int,int,int>
#define trll trio<ll,ll,ll>

//STL pair input
template<typename T1, typename T2>
inline istream& operator >> (istream& os, pair<T1, T2>& t){ return os >> t.first >> t.second;}
template<typename T1, typename T2, typename T3>
inline istream& operator >> (istream& os, trio<T1, T2, T3>& t){ return os >> t.x >> t.y >> t.z; }
template<typename T>inline istream &operator>>(istream &os, vector<T>& v){for(T &i:v){os>>i;}return os;}
template<typename T>inline istream &operator>>(istream &os, vector<vector<T>>& v){for(vector<T> &i : v){os>>i;}return os;}

//STL debug by print
template<typename T1, typename T2>
inline ostream& operator << (ostream& os, const pair<T1, T2>& t){ return os << t.first << " " << t.second<<endl; }
template<typename T1, typename T2, typename T3>
inline ostream& operator << (ostream& os, const trio<T1, T2, T3>& t){ return os << t.x << " " << t.y << " " << t.z<<endl; }
template<typename T>inline void printarr(T arr[], int n){for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const vector<T>& v){for(T i:v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const vector<vector<T>>& v){for(vector<T> i:v){os<<i;}return os;}
template<typename T>inline ostream &operator<<(ostream &os,const unordered_set<T>&v){for(T i:v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const set<T>&v){for(T i:v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const set<T, greater<T> >&v){for(T i:v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const multiset<T>&v){for(T i:v){os<<i<<" ";}return os<<endl;}
template<typename T>inline ostream &operator<<(ostream &os,const multiset<T, greater<T> >&v){for(T i:v){os<<i<<" ";}return os<<endl;}
template<typename T1, typename T2>
inline ostream &operator << (ostream & os,const unordered_map<T1, T2>& v){for(pair<T1, T2> i : v){os<<i;}return os<<endl;}
template<typename T1, typename T2>
inline ostream &operator << (ostream & os,const map<T1, T2>& v){for(pair<T1, T2> i : v){os<<i;}return os<<endl;}
template<typename T1, typename T2>
inline ostream &operator << (ostream & os,const multimap<T1, T2>& v){for(pair<T1, T2> i : v){os<<i;}return os<<endl;}
inline void printgraph(vi arr[], int n){for(int i=0;i<n;i++){cout<<i<<" --> ";cout<<arr[i];}cout<<endl;}

// inline helper functions
template<typename T>inline T max(vector<T> a){return *max_element(all(a));}
template<typename T>inline T min(vector<T> a){return *min_element(all(a));}
template<typename T1, typename T2>inline T1 setbit(T1 mask, T2 pos){return mask |= (1 << pos);}
template<typename T1, typename T2>inline T1 resetbit(T1 mask, T2 pos){return mask &= ~(1 << pos);}
template<typename T1, typename T2>inline T1 togglebit(T1 mask, T2 pos){return mask ^= (1 << pos);}
template<typename T1, typename T2>inline bool checkbit(T1 mask, T2 pos){return (bool)(mask & (1 << pos));}
inline ll binexp(ll a, ll b, ll m){a%=m;ll res=1;while(b){if(b&1)res=(res*a)%m;a=(a*a)%m;b>>=1;}return res;}
inline string toBase(ll a,ll b=2){string s="";if(!a)return"0";while(a){s=to_string(a%b)+s;a/=b;}return s;}
inline ll digsum(ll n){ll ans=0;while(n){ans+=n%10;n/=10;}return ans;}
inline ll sq(ll a){return a*a;}
inline ll cube(ll a){return a*a*a;}
inline double dist(pii a, pii b){return sqrt(sq(a.ff-b.ff) + sq(a.ss-b.ss));}
inline bool ispow2(ll i){return i && (i & -i) == i;}
inline bool isdigit(char c){if(c>='0' && c<='9')return true;return false;}
inline bool isupper(char c){if(c>='A' && c<='Z')return true;return false;}
inline bool islower(char c){if(c>='a' && c<='z')return true;return false;}
inline int toInt(string s){int num;istringstream iss(s);iss>>num;return num;}
inline ll toLLong(string s){ll num;istringstream iss(s);iss>>num;return num;}
void solve();
void solve(ll);
void solve(ll,ll);

//vi dx = {-1,0,1,0} , dy = {0,1,0,-1}; // Clockwise 4 Direction. Start at north
vi dx = {-1,-1,0,1,1,1,0,-1} , dy= {0,1,1,1,0,-1,-1,-1}; // Clockwise 8 Direction. Start at north
//vi dx = {1,-1,1,-1,2,2,-2,-2} , dy = {2,2,-2,-2,1,-1,1,-1}; // Knight Direction
//vi dx = {2,-2,1,1,-1,-1} , dy= {0,0,1,-1,1,-1}; // Hexagonal Direction

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
	//cin>>t;
	//cout<<t<<endl;
	//generateSieve();

	int n;
	while(cin>>n){
		//cout<<"Case "<<(++i)<<": ";
		solve(n);
	}
	//if(stress==1){compare();}
	return 0;
}

/*
AC code. This problem is 0-1 BFS. This appproach provides improvement over the log factor
The time complexity if O(E + V) which is = 9*10^6 per test-case
As the problem states that there are atmost 50 test-cases, the code amounts to atmost 5*10^8
*/

void solve(ll n){
	ll i, j, m;
	cin>>m;
	vs arr(n);
	cin>>arr;
	int q;
	cin>>q;
	while(q--){
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		x1--;y1--;x2--;y2--;
		
		deque<pii> q;
		q.push_front({x1, y1});
		vvll d(n, vll(m, inf));
		d[x1][y1]=0;
		while(!q.empty()){
			pii t = q.front();
			q.pop_front();

			if(t == pii(mp(x2,y2))){
				cout<<d[x2][y2];ce
				break;
			}

			for(int k=0;k<8;k++){
				int x = t.ff+dx[k];
				int y = t.ss+dy[k];
				if(x>=0 && x<n && y>=0 && y<m){
					int flag = (arr[t.ff][t.ss]-'0')!=k;
					int newd = d[t.ff][t.ss] + flag;
					if(d[x][y] > newd){
						d[x][y] = newd;
						if(flag)
							q.pb({x,y});
						else
							q.push_front({x,y});
					}
				}
			}
		}
	}
}



/*
// This approach is faster than the previous one.
// This is standard dijkstra but even the complexity of dijkstra is O((E+V)logV) and this problem
// has E = 8V and V = 10^6 with multiple test-cases.
// So total is 9V*log(10^6) = 9*10^6 * 6*4 = 2 * 10^8 per test-case which in itself is too much.
// And as the problem states that there are atmost 50 test-cases, the code amounts to 10^10 which is TLE

void solve(ll n){
	ll i, j, m;
	cin>>m;
	vs arr(n);
	cin>>arr;
	int q;
	cin>>q;
	while(q--){
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		x1--;y1--;x2--;y2--;
		set<pair<int, pii>> q;
		q.insert({0, {x1, y1}});
		vvll d(n, vll(m, inf));
		d[x1][y1]=0;
		while(!q.empty()){
			auto t = *q.begin();
			q.erase(q.begin());
			//if(t.ss.ff == x2 && )
			for(int k=0;k<8;k++){
				int x = t.ss.ff+dx[k];
				int y = t.ss.ss+dy[k];
				if(x>=0 && x<n && y>=0 && y<m){
					int newd = t.ff + ((arr[t.ss.ff][t.ss.ss]-'0')!=k);
					if(d[x][y] > newd){
						d[x][y] = newd;
						q.insert({newd, {x,y}});
					}
				}
			}
		}
		cout<<d[x2][y2];ce
	}
}
*/


/*
// This is literal brute force which keeps on adding a node as long as it is capable of relaxing some
// other node. This results in the same position in the grid getting relaxed again and again
// In worts case, the time complexity of this code can reach upto O(EV) which is too much

void solve(ll n){
	ll i, j, m;
	cin>>m;
	vs arr(n);
	cin>>arr;
	int q;
	cin>>q;
	while(q--){
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		x1--;y1--;x2--;y2--;
		queue<pii> q;
		q.push({x1, y1});
		vvll d(n, vll(m, inf));
		d[x1][y1]=0;
		while(!q.empty()){//cout<<d;ce
			pii t = q.front();//w(t)ce
			q.pop();
			for(int k=0;k<8;k++){
				int x = t.ff+dx[k];
				int y = t.ss+dy[k];
				if(x>=0 && x<n && y>=0 && y<m){
					int newd = d[t.ff][t.ss]+((arr[t.ff][t.ss]-'0')!=k);
					if(d[x][y] > newd){
						d[x][y] = newd;
						q.push({x,y});
					}
				}
			}
		}//cout<<d;ce
		cout<<d[x2][y2];ce
	}
}*/
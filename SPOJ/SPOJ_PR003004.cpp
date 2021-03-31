#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
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
#define vpii vector<pair<int, int> >
#define vpll vector<pair<ll, ll> >
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define maxx(a, b, c) max((a), max((b), (c)))
#define minn(a, b, c) min((a), min((b), (c)))
#define dup(x) (x).resize(distance((x).begin(), unique(all(x))))
#define maxn 100001
#define mem memset(dp, -1, sizeof dp)
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
inline ll binexp(ll a, ll b, ll m){a%=m;ll res=1;while(b>0){if(b&1)res=(res*a)%m;a=(a*a)%m;b>>=1;}return res;}
inline bool ispow2(ll i){return i && (i & -i) == i;}
inline string toBin(ll a){string s="";while(a>0){s=to_string(a&1)+s;a>>=1;}return s;}
inline bool isdigit(char c){if(c>='0' && c<='9')return true;return false;}
inline bool isupper(char c){if(c>='A' && c<='Z')return true;return false;}
inline bool islower(char c){if(c>='a' && c<='z')return true;return false;}
void solve(ll, ll);

ll dp[20][200];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	mem;
	ll a, b;
	cin>>a>>b;
	while(t--){
		solve(a, b);
		cin>>a>>b;
	}
	return 0;
}

ll recur(string &arr, int i, ll sum, int t){
	if(i==0){
		return sum;
	}
	if(dp[i][sum]!=-1 && !t){
		return dp[i][sum];
	}
	int lmt = t?arr[i]-'0':9;
	ll ans = 0;
	for(int j=0;j<=lmt;j++){
		ans += recur(arr, i-1, sum+j, t&(j==lmt));
	}
	if(!t){
		dp[i][sum]= ans;
	}
	return ans;
}
void solve(ll a, ll b){
	string bs=to_string(b);
	bs+="0";
	reverse(all(bs));
	ll ans = recur(bs, bs.size()-1, 0, 1);
	ll ans1 = 0;
	if(a>0){
		string as=to_string(a-1);
		as+="0";
		reverse(all(as));
		ans1 = recur(as, as.size()-1, 0, 1);
	}
	cout<<ans-ans1<<endl;
}

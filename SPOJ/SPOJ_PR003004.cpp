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
#define mem1 memset(dp1, -1, sizeof dp1)
#define fori for(i=0;i<n;i++)
#define forj for(j=0;j<m;j++)
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
inline ll binexp(ll a, ll b, ll m){a%=m;ll res=1;while(b>0){if(b&1)res=(res*a)%m;a=(a*a)%m;b>>=1;}return res;}
inline bool ispow2(ll i){return i && (i & -i) == i;}
inline string toBin(ll a){string s="";while(a>0){s=to_string(a&1)+s;a>>=1;}return s;}
inline bool isdigit(char c){if(c>='0' && c<='9')return true;return false;}
inline bool isupper(char c){if(c>='A' && c<='Z')return true;return false;}
inline bool islower(char c){if(c>='a' && c<='z')return true;return false;}
void solve();

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
	while(t--){
		solve();
	}
	return 0;
}

// Most optimized and updated on 08-April-2021 template
ll recur(string &arr, int i, ll sum, int t){
	int n = (int)arr.size();
	if(i==0){
		return sum;
	}
	ll &ret = dp[i][sum];
	if(!t && ret!=-1){
		return ret;
	}
	int lmt = t?arr[n-i]-'0':9;
	ll ans = 0;
	for(int j=0;j<=lmt;j++){
		ans += recur(arr, i-1, sum+j, t&(j==lmt));
	}
	return t?ans:ret=ans;
}
void solve(){
	ll a, b;
	cin>>a>>b;
	string bs=to_string(b);
	ll ans = recur(bs, bs.size(), 0, 1);
	ll ans1 = 0;
	if(a>0){
		string as=to_string(a-1);
		ans1 = recur(as, as.size(), 0, 1);
	}
	cout<<ans-ans1<<endl;
}

/*
For good debug/visualization view

void printdp(int a, int n){
	int i, j;cout<<endl;
	for(i=0;i<3;i++){
		for(int x=a;x<=n;x++){
			cout<<"\t";
		}
		for(j=0;j<=20;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}
ll recur(string &arr, int i, ll sum, int t){
	int n = (int)arr.size();
	for(int x=i;x<n;x++){
		cout<<"\t";
	}
	w(i);w(sum);w(t);
	if(i==0){
		cout<<"\treturn "<<sum;
		return sum;
	}
	ll &ret = dp[i][sum];
	if(ret!=-1 && !t){
		cout<<"\treturndp "<<ret;
		return ret;
	}
	int lmt = t?arr[n-i]-'0':9;
	ll ans = 0;
	for(int j=0;j<=lmt;j++){
		cout<<endl;
		for(int x=i;x<=n;x++){
			cout<<"\t";
		}w(j);cout<<"--->";
		ans += recur(arr, i-1, sum+j, t&(j==lmt));
	}
	printdp(i, n);
	return t?ans:ret=ans;
}
void solve(){
	ll a, b;
	cin>>a>>b;
	string bs=to_string(b);
	ll ans = recur(bs, bs.size(), 0, 1);
	ll ans1 = 0;
	if(a>0){
		string as=to_string(a-1);
		ans1 = recur(as, as.size(), 0, 1);
	}
	cout<<"AC Output: "<<ans-ans1<<endl;
}

Input:
82 1000

AC Output:
12844

Debug output for visualization:
i=4 sum=0 t=1 
	j=0 --->	i=3 sum=0 t=0 
		j=0 --->		i=2 sum=0 t=0 
			j=0 --->			i=1 sum=0 t=0 
				j=0 --->				i=0 sum=0 t=0 	return 0
				j=1 --->				i=0 sum=1 t=0 	return 1
				j=2 --->				i=0 sum=2 t=0 	return 2
				j=3 --->				i=0 sum=3 t=0 	return 3
				j=4 --->				i=0 sum=4 t=0 	return 4
				j=5 --->				i=0 sum=5 t=0 	return 5
				j=6 --->				i=0 sum=6 t=0 	return 6
				j=7 --->				i=0 sum=7 t=0 	return 7
				j=8 --->				i=0 sum=8 t=0 	return 8
				j=9 --->				i=0 sum=9 t=0 	return 9
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			j=1 --->			i=1 sum=1 t=0 
				j=0 --->				i=0 sum=1 t=0 	return 1
				j=1 --->				i=0 sum=2 t=0 	return 2
				j=2 --->				i=0 sum=3 t=0 	return 3
				j=3 --->				i=0 sum=4 t=0 	return 4
				j=4 --->				i=0 sum=5 t=0 	return 5
				j=5 --->				i=0 sum=6 t=0 	return 6
				j=6 --->				i=0 sum=7 t=0 	return 7
				j=7 --->				i=0 sum=8 t=0 	return 8
				j=8 --->				i=0 sum=9 t=0 	return 9
				j=9 --->				i=0 sum=10 t=0 	return 10
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			j=2 --->			i=1 sum=2 t=0 
				j=0 --->				i=0 sum=2 t=0 	return 2
				j=1 --->				i=0 sum=3 t=0 	return 3
				j=2 --->				i=0 sum=4 t=0 	return 4
				j=3 --->				i=0 sum=5 t=0 	return 5
				j=4 --->				i=0 sum=6 t=0 	return 6
				j=5 --->				i=0 sum=7 t=0 	return 7
				j=6 --->				i=0 sum=8 t=0 	return 8
				j=7 --->				i=0 sum=9 t=0 	return 9
				j=8 --->				i=0 sum=10 t=0 	return 10
				j=9 --->				i=0 sum=11 t=0 	return 11
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			j=3 --->			i=1 sum=3 t=0 
				j=0 --->				i=0 sum=3 t=0 	return 3
				j=1 --->				i=0 sum=4 t=0 	return 4
				j=2 --->				i=0 sum=5 t=0 	return 5
				j=3 --->				i=0 sum=6 t=0 	return 6
				j=4 --->				i=0 sum=7 t=0 	return 7
				j=5 --->				i=0 sum=8 t=0 	return 8
				j=6 --->				i=0 sum=9 t=0 	return 9
				j=7 --->				i=0 sum=10 t=0 	return 10
				j=8 --->				i=0 sum=11 t=0 	return 11
				j=9 --->				i=0 sum=12 t=0 	return 12
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			j=4 --->			i=1 sum=4 t=0 
				j=0 --->				i=0 sum=4 t=0 	return 4
				j=1 --->				i=0 sum=5 t=0 	return 5
				j=2 --->				i=0 sum=6 t=0 	return 6
				j=3 --->				i=0 sum=7 t=0 	return 7
				j=4 --->				i=0 sum=8 t=0 	return 8
				j=5 --->				i=0 sum=9 t=0 	return 9
				j=6 --->				i=0 sum=10 t=0 	return 10
				j=7 --->				i=0 sum=11 t=0 	return 11
				j=8 --->				i=0 sum=12 t=0 	return 12
				j=9 --->				i=0 sum=13 t=0 	return 13
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			j=5 --->			i=1 sum=5 t=0 
				j=0 --->				i=0 sum=5 t=0 	return 5
				j=1 --->				i=0 sum=6 t=0 	return 6
				j=2 --->				i=0 sum=7 t=0 	return 7
				j=3 --->				i=0 sum=8 t=0 	return 8
				j=4 --->				i=0 sum=9 t=0 	return 9
				j=5 --->				i=0 sum=10 t=0 	return 10
				j=6 --->				i=0 sum=11 t=0 	return 11
				j=7 --->				i=0 sum=12 t=0 	return 12
				j=8 --->				i=0 sum=13 t=0 	return 13
				j=9 --->				i=0 sum=14 t=0 	return 14
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			j=6 --->			i=1 sum=6 t=0 
				j=0 --->				i=0 sum=6 t=0 	return 6
				j=1 --->				i=0 sum=7 t=0 	return 7
				j=2 --->				i=0 sum=8 t=0 	return 8
				j=3 --->				i=0 sum=9 t=0 	return 9
				j=4 --->				i=0 sum=10 t=0 	return 10
				j=5 --->				i=0 sum=11 t=0 	return 11
				j=6 --->				i=0 sum=12 t=0 	return 12
				j=7 --->				i=0 sum=13 t=0 	return 13
				j=8 --->				i=0 sum=14 t=0 	return 14
				j=9 --->				i=0 sum=15 t=0 	return 15
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			j=7 --->			i=1 sum=7 t=0 
				j=0 --->				i=0 sum=7 t=0 	return 7
				j=1 --->				i=0 sum=8 t=0 	return 8
				j=2 --->				i=0 sum=9 t=0 	return 9
				j=3 --->				i=0 sum=10 t=0 	return 10
				j=4 --->				i=0 sum=11 t=0 	return 11
				j=5 --->				i=0 sum=12 t=0 	return 12
				j=6 --->				i=0 sum=13 t=0 	return 13
				j=7 --->				i=0 sum=14 t=0 	return 14
				j=8 --->				i=0 sum=15 t=0 	return 15
				j=9 --->				i=0 sum=16 t=0 	return 16
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			j=8 --->			i=1 sum=8 t=0 
				j=0 --->				i=0 sum=8 t=0 	return 8
				j=1 --->				i=0 sum=9 t=0 	return 9
				j=2 --->				i=0 sum=10 t=0 	return 10
				j=3 --->				i=0 sum=11 t=0 	return 11
				j=4 --->				i=0 sum=12 t=0 	return 12
				j=5 --->				i=0 sum=13 t=0 	return 13
				j=6 --->				i=0 sum=14 t=0 	return 14
				j=7 --->				i=0 sum=15 t=0 	return 15
				j=8 --->				i=0 sum=16 t=0 	return 16
				j=9 --->				i=0 sum=17 t=0 	return 17
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 125 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			j=9 --->			i=1 sum=9 t=0 
				j=0 --->				i=0 sum=9 t=0 	return 9
				j=1 --->				i=0 sum=10 t=0 	return 10
				j=2 --->				i=0 sum=11 t=0 	return 11
				j=3 --->				i=0 sum=12 t=0 	return 12
				j=4 --->				i=0 sum=13 t=0 	return 13
				j=5 --->				i=0 sum=14 t=0 	return 14
				j=6 --->				i=0 sum=15 t=0 	return 15
				j=7 --->				i=0 sum=16 t=0 	return 16
				j=8 --->				i=0 sum=17 t=0 	return 17
				j=9 --->				i=0 sum=18 t=0 	return 18
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 125 135 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			45 55 65 75 85 95 105 115 125 135 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			900 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

		j=1 --->		i=2 sum=1 t=0 
			j=0 --->			i=1 sum=1 t=0 	returndp 55
			j=1 --->			i=1 sum=2 t=0 	returndp 65
			j=2 --->			i=1 sum=3 t=0 	returndp 75
			j=3 --->			i=1 sum=4 t=0 	returndp 85
			j=4 --->			i=1 sum=5 t=0 	returndp 95
			j=5 --->			i=1 sum=6 t=0 	returndp 105
			j=6 --->			i=1 sum=7 t=0 	returndp 115
			j=7 --->			i=1 sum=8 t=0 	returndp 125
			j=8 --->			i=1 sum=9 t=0 	returndp 135
			j=9 --->			i=1 sum=10 t=0 
				j=0 --->				i=0 sum=10 t=0 	return 10
				j=1 --->				i=0 sum=11 t=0 	return 11
				j=2 --->				i=0 sum=12 t=0 	return 12
				j=3 --->				i=0 sum=13 t=0 	return 13
				j=4 --->				i=0 sum=14 t=0 	return 14
				j=5 --->				i=0 sum=15 t=0 	return 15
				j=6 --->				i=0 sum=16 t=0 	return 16
				j=7 --->				i=0 sum=17 t=0 	return 17
				j=8 --->				i=0 sum=18 t=0 	return 18
				j=9 --->				i=0 sum=19 t=0 	return 19
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 125 135 145 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				900 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			45 55 65 75 85 95 105 115 125 135 145 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			900 1000 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

		j=2 --->		i=2 sum=2 t=0 
			j=0 --->			i=1 sum=2 t=0 	returndp 65
			j=1 --->			i=1 sum=3 t=0 	returndp 75
			j=2 --->			i=1 sum=4 t=0 	returndp 85
			j=3 --->			i=1 sum=5 t=0 	returndp 95
			j=4 --->			i=1 sum=6 t=0 	returndp 105
			j=5 --->			i=1 sum=7 t=0 	returndp 115
			j=6 --->			i=1 sum=8 t=0 	returndp 125
			j=7 --->			i=1 sum=9 t=0 	returndp 135
			j=8 --->			i=1 sum=10 t=0 	returndp 145
			j=9 --->			i=1 sum=11 t=0 
				j=0 --->				i=0 sum=11 t=0 	return 11
				j=1 --->				i=0 sum=12 t=0 	return 12
				j=2 --->				i=0 sum=13 t=0 	return 13
				j=3 --->				i=0 sum=14 t=0 	return 14
				j=4 --->				i=0 sum=15 t=0 	return 15
				j=5 --->				i=0 sum=16 t=0 	return 16
				j=6 --->				i=0 sum=17 t=0 	return 17
				j=7 --->				i=0 sum=18 t=0 	return 18
				j=8 --->				i=0 sum=19 t=0 	return 19
				j=9 --->				i=0 sum=20 t=0 	return 20
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 125 135 145 155 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				900 1000 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			45 55 65 75 85 95 105 115 125 135 145 155 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			900 1000 1100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

		j=3 --->		i=2 sum=3 t=0 
			j=0 --->			i=1 sum=3 t=0 	returndp 75
			j=1 --->			i=1 sum=4 t=0 	returndp 85
			j=2 --->			i=1 sum=5 t=0 	returndp 95
			j=3 --->			i=1 sum=6 t=0 	returndp 105
			j=4 --->			i=1 sum=7 t=0 	returndp 115
			j=5 --->			i=1 sum=8 t=0 	returndp 125
			j=6 --->			i=1 sum=9 t=0 	returndp 135
			j=7 --->			i=1 sum=10 t=0 	returndp 145
			j=8 --->			i=1 sum=11 t=0 	returndp 155
			j=9 --->			i=1 sum=12 t=0 
				j=0 --->				i=0 sum=12 t=0 	return 12
				j=1 --->				i=0 sum=13 t=0 	return 13
				j=2 --->				i=0 sum=14 t=0 	return 14
				j=3 --->				i=0 sum=15 t=0 	return 15
				j=4 --->				i=0 sum=16 t=0 	return 16
				j=5 --->				i=0 sum=17 t=0 	return 17
				j=6 --->				i=0 sum=18 t=0 	return 18
				j=7 --->				i=0 sum=19 t=0 	return 19
				j=8 --->				i=0 sum=20 t=0 	return 20
				j=9 --->				i=0 sum=21 t=0 	return 21
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 125 135 145 155 165 -1 -1 -1 -1 -1 -1 -1 -1 
				900 1000 1100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			45 55 65 75 85 95 105 115 125 135 145 155 165 -1 -1 -1 -1 -1 -1 -1 -1 
			900 1000 1100 1200 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

		j=4 --->		i=2 sum=4 t=0 
			j=0 --->			i=1 sum=4 t=0 	returndp 85
			j=1 --->			i=1 sum=5 t=0 	returndp 95
			j=2 --->			i=1 sum=6 t=0 	returndp 105
			j=3 --->			i=1 sum=7 t=0 	returndp 115
			j=4 --->			i=1 sum=8 t=0 	returndp 125
			j=5 --->			i=1 sum=9 t=0 	returndp 135
			j=6 --->			i=1 sum=10 t=0 	returndp 145
			j=7 --->			i=1 sum=11 t=0 	returndp 155
			j=8 --->			i=1 sum=12 t=0 	returndp 165
			j=9 --->			i=1 sum=13 t=0 
				j=0 --->				i=0 sum=13 t=0 	return 13
				j=1 --->				i=0 sum=14 t=0 	return 14
				j=2 --->				i=0 sum=15 t=0 	return 15
				j=3 --->				i=0 sum=16 t=0 	return 16
				j=4 --->				i=0 sum=17 t=0 	return 17
				j=5 --->				i=0 sum=18 t=0 	return 18
				j=6 --->				i=0 sum=19 t=0 	return 19
				j=7 --->				i=0 sum=20 t=0 	return 20
				j=8 --->				i=0 sum=21 t=0 	return 21
				j=9 --->				i=0 sum=22 t=0 	return 22
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 125 135 145 155 165 175 -1 -1 -1 -1 -1 -1 -1 
				900 1000 1100 1200 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			45 55 65 75 85 95 105 115 125 135 145 155 165 175 -1 -1 -1 -1 -1 -1 -1 
			900 1000 1100 1200 1300 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

		j=5 --->		i=2 sum=5 t=0 
			j=0 --->			i=1 sum=5 t=0 	returndp 95
			j=1 --->			i=1 sum=6 t=0 	returndp 105
			j=2 --->			i=1 sum=7 t=0 	returndp 115
			j=3 --->			i=1 sum=8 t=0 	returndp 125
			j=4 --->			i=1 sum=9 t=0 	returndp 135
			j=5 --->			i=1 sum=10 t=0 	returndp 145
			j=6 --->			i=1 sum=11 t=0 	returndp 155
			j=7 --->			i=1 sum=12 t=0 	returndp 165
			j=8 --->			i=1 sum=13 t=0 	returndp 175
			j=9 --->			i=1 sum=14 t=0 
				j=0 --->				i=0 sum=14 t=0 	return 14
				j=1 --->				i=0 sum=15 t=0 	return 15
				j=2 --->				i=0 sum=16 t=0 	return 16
				j=3 --->				i=0 sum=17 t=0 	return 17
				j=4 --->				i=0 sum=18 t=0 	return 18
				j=5 --->				i=0 sum=19 t=0 	return 19
				j=6 --->				i=0 sum=20 t=0 	return 20
				j=7 --->				i=0 sum=21 t=0 	return 21
				j=8 --->				i=0 sum=22 t=0 	return 22
				j=9 --->				i=0 sum=23 t=0 	return 23
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 -1 -1 -1 -1 -1 -1 
				900 1000 1100 1200 1300 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 -1 -1 -1 -1 -1 -1 
			900 1000 1100 1200 1300 1400 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

		j=6 --->		i=2 sum=6 t=0 
			j=0 --->			i=1 sum=6 t=0 	returndp 105
			j=1 --->			i=1 sum=7 t=0 	returndp 115
			j=2 --->			i=1 sum=8 t=0 	returndp 125
			j=3 --->			i=1 sum=9 t=0 	returndp 135
			j=4 --->			i=1 sum=10 t=0 	returndp 145
			j=5 --->			i=1 sum=11 t=0 	returndp 155
			j=6 --->			i=1 sum=12 t=0 	returndp 165
			j=7 --->			i=1 sum=13 t=0 	returndp 175
			j=8 --->			i=1 sum=14 t=0 	returndp 185
			j=9 --->			i=1 sum=15 t=0 
				j=0 --->				i=0 sum=15 t=0 	return 15
				j=1 --->				i=0 sum=16 t=0 	return 16
				j=2 --->				i=0 sum=17 t=0 	return 17
				j=3 --->				i=0 sum=18 t=0 	return 18
				j=4 --->				i=0 sum=19 t=0 	return 19
				j=5 --->				i=0 sum=20 t=0 	return 20
				j=6 --->				i=0 sum=21 t=0 	return 21
				j=7 --->				i=0 sum=22 t=0 	return 22
				j=8 --->				i=0 sum=23 t=0 	return 23
				j=9 --->				i=0 sum=24 t=0 	return 24
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 -1 -1 -1 -1 -1 
				900 1000 1100 1200 1300 1400 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 -1 -1 -1 -1 -1 
			900 1000 1100 1200 1300 1400 1500 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

		j=7 --->		i=2 sum=7 t=0 
			j=0 --->			i=1 sum=7 t=0 	returndp 115
			j=1 --->			i=1 sum=8 t=0 	returndp 125
			j=2 --->			i=1 sum=9 t=0 	returndp 135
			j=3 --->			i=1 sum=10 t=0 	returndp 145
			j=4 --->			i=1 sum=11 t=0 	returndp 155
			j=5 --->			i=1 sum=12 t=0 	returndp 165
			j=6 --->			i=1 sum=13 t=0 	returndp 175
			j=7 --->			i=1 sum=14 t=0 	returndp 185
			j=8 --->			i=1 sum=15 t=0 	returndp 195
			j=9 --->			i=1 sum=16 t=0 
				j=0 --->				i=0 sum=16 t=0 	return 16
				j=1 --->				i=0 sum=17 t=0 	return 17
				j=2 --->				i=0 sum=18 t=0 	return 18
				j=3 --->				i=0 sum=19 t=0 	return 19
				j=4 --->				i=0 sum=20 t=0 	return 20
				j=5 --->				i=0 sum=21 t=0 	return 21
				j=6 --->				i=0 sum=22 t=0 	return 22
				j=7 --->				i=0 sum=23 t=0 	return 23
				j=8 --->				i=0 sum=24 t=0 	return 24
				j=9 --->				i=0 sum=25 t=0 	return 25
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 -1 -1 -1 -1 
				900 1000 1100 1200 1300 1400 1500 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 -1 -1 -1 -1 
			900 1000 1100 1200 1300 1400 1500 1600 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

		j=8 --->		i=2 sum=8 t=0 
			j=0 --->			i=1 sum=8 t=0 	returndp 125
			j=1 --->			i=1 sum=9 t=0 	returndp 135
			j=2 --->			i=1 sum=10 t=0 	returndp 145
			j=3 --->			i=1 sum=11 t=0 	returndp 155
			j=4 --->			i=1 sum=12 t=0 	returndp 165
			j=5 --->			i=1 sum=13 t=0 	returndp 175
			j=6 --->			i=1 sum=14 t=0 	returndp 185
			j=7 --->			i=1 sum=15 t=0 	returndp 195
			j=8 --->			i=1 sum=16 t=0 	returndp 205
			j=9 --->			i=1 sum=17 t=0 
				j=0 --->				i=0 sum=17 t=0 	return 17
				j=1 --->				i=0 sum=18 t=0 	return 18
				j=2 --->				i=0 sum=19 t=0 	return 19
				j=3 --->				i=0 sum=20 t=0 	return 20
				j=4 --->				i=0 sum=21 t=0 	return 21
				j=5 --->				i=0 sum=22 t=0 	return 22
				j=6 --->				i=0 sum=23 t=0 	return 23
				j=7 --->				i=0 sum=24 t=0 	return 24
				j=8 --->				i=0 sum=25 t=0 	return 25
				j=9 --->				i=0 sum=26 t=0 	return 26
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 215 -1 -1 -1 
				900 1000 1100 1200 1300 1400 1500 1600 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 215 -1 -1 -1 
			900 1000 1100 1200 1300 1400 1500 1600 1700 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

		j=9 --->		i=2 sum=9 t=0 
			j=0 --->			i=1 sum=9 t=0 	returndp 135
			j=1 --->			i=1 sum=10 t=0 	returndp 145
			j=2 --->			i=1 sum=11 t=0 	returndp 155
			j=3 --->			i=1 sum=12 t=0 	returndp 165
			j=4 --->			i=1 sum=13 t=0 	returndp 175
			j=5 --->			i=1 sum=14 t=0 	returndp 185
			j=6 --->			i=1 sum=15 t=0 	returndp 195
			j=7 --->			i=1 sum=16 t=0 	returndp 205
			j=8 --->			i=1 sum=17 t=0 	returndp 215
			j=9 --->			i=1 sum=18 t=0 
				j=0 --->				i=0 sum=18 t=0 	return 18
				j=1 --->				i=0 sum=19 t=0 	return 19
				j=2 --->				i=0 sum=20 t=0 	return 20
				j=3 --->				i=0 sum=21 t=0 	return 21
				j=4 --->				i=0 sum=22 t=0 	return 22
				j=5 --->				i=0 sum=23 t=0 	return 23
				j=6 --->				i=0 sum=24 t=0 	return 24
				j=7 --->				i=0 sum=25 t=0 	return 25
				j=8 --->				i=0 sum=26 t=0 	return 26
				j=9 --->				i=0 sum=27 t=0 	return 27
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 215 225 -1 -1 
				900 1000 1100 1200 1300 1400 1500 1600 1700 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 215 225 -1 -1 
			900 1000 1100 1200 1300 1400 1500 1600 1700 1800 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

		-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
		45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 215 225 -1 -1 
		900 1000 1100 1200 1300 1400 1500 1600 1700 1800 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
		13500 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

	j=1 --->	i=3 sum=1 t=1 
		j=0 --->		i=2 sum=1 t=1 
			j=0 --->			i=1 sum=1 t=1 
				j=0 --->				i=0 sum=1 t=1 	return 1
				-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 215 225 -1 -1 
				900 1000 1100 1200 1300 1400 1500 1600 1700 1800 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
				13500 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 215 225 -1 -1 
			900 1000 1100 1200 1300 1400 1500 1600 1700 1800 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
			13500 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

		-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
		45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 215 225 -1 -1 
		900 1000 1100 1200 1300 1400 1500 1600 1700 1800 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
		13500 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

	-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
	45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 215 225 -1 -1 
	900 1000 1100 1200 1300 1400 1500 1600 1700 1800 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
	13500 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
i=2 sum=0 t=1 
	j=0 --->	i=1 sum=0 t=0 	returndp 45
	j=1 --->	i=1 sum=1 t=0 	returndp 55
	j=2 --->	i=1 sum=2 t=0 	returndp 65
	j=3 --->	i=1 sum=3 t=0 	returndp 75
	j=4 --->	i=1 sum=4 t=0 	returndp 85
	j=5 --->	i=1 sum=5 t=0 	returndp 95
	j=6 --->	i=1 sum=6 t=0 	returndp 105
	j=7 --->	i=1 sum=7 t=0 	returndp 115
	j=8 --->	i=1 sum=8 t=1 
		j=0 --->		i=0 sum=8 t=0 	return 8
		j=1 --->		i=0 sum=9 t=1 	return 9
		-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
		45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 215 225 -1 -1 
		900 1000 1100 1200 1300 1400 1500 1600 1700 1800 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
		13500 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

	-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
	45 55 65 75 85 95 105 115 125 135 145 155 165 175 185 195 205 215 225 -1 -1 
	900 1000 1100 1200 1300 1400 1500 1600 1700 1800 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
	13500 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

AC Output: 12844

*/
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int> >
#define vvll vector<vector<ll> >
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pair<int, int> >
#define vpll vector<pair<ll, ll> >
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define maxx(a, b, c) max((a), max((b), (c)))
#define minn(a, b, c) min((a), min((b), (c)))
const ll mod=1e9+7;
const ll inf = (1<<30);
const double eps = (double)1e-6;
const double pi = 3.14159265358979323;

using namespace std;

template <typename T1, typename T2, typename T3>struct trio{T1 x; T2 y; T3 z; trio(){};trio(T1 _x, T2 _y, T3 _z):x(_x), y(_y), z(_z){}};
#define tri trio<int,int,int>
#define trll trio<ll,ll,ll>

//STL pair input
template<typename T1, typename T2>inline std::istream& operator >> (std::istream& os, pair<T1, T2>& t){ os >> t.first; os >> t.second; return os; }

//STL debug by print
template<typename T1, typename T2>inline std::ostream& operator << (std::ostream& os, const pair<T1, T2>& t){ return os << t.first << " " << t.second; }
template<typename T1, typename T2, typename T3>inline std::ostream& operator << (std::ostream& os, const trio<T1, T2, T3>& t){ return os << t.x << " " << t.y << " " << t.z; }
template<typename T>void printarr(T arr[], int n){for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<T>& v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<vector<T>>& v){for(vector<T> i : v){os<<i;}return os;}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::set<T>&v){for(T i : v){os<<i<<" ";}return os<<endl;}
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){for(pair<T1, T2> i : v){os<<i;}return os;}
void printgraph(vi arr[], int n){for(int i=0;i<n;i++){cout<<i<<" --> ";cout<<arr[i];}cout<<endl;}
ll binexp(ll a, ll b, ll m){a%=m;ll res=1;while(b>0){if(b&1)res=(res*a)%m;a=(a*a)%m;b>>=1;}return res;}
void solve();

string toBin(ll a){
	string s="";
	while(a>0){
		s=to_string(a&1)+s;
		a>>=1;
	}
	return s;
}
void genTestCases(int i){
	srand(i);
	int n=1+rand()%10;
	int k=1+rand()%n;
	cout<<n<<" "<<k<<endl;
	while(n--){
		cout<<1+rand()%10000<<" "<<rand()%2<<" "<<rand()%2<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif
	int t=1;
	cin>>t;
	for(int i=0;i<t;i++){
		//cin<<"Case "<<(i)<<" : "
		//genTestCases(i);
		solve();
	}
	return 0;
}

void solve(){
	ll i, j, n, sum, num;
	cin>>num>>sum;
	string s;
	s=to_string(num);
	n=s.size();
	i=0;
	vi dp(n+1, 0);
	for(i=1;i<=n;i++){
		dp[i]+=dp[i-1]+(s[i-1]-'0');
	}
	if(dp[n]<=sum){
		cout<<0<<endl;
		return;
	}
	i=0;
	ll ans=0;
	while(i<n){
		if(dp[i+1]<sum){
			ans=ans*10+(s[i]-'0');
		}else{
			ans++;
			while(i<n){
				ans=ans*10;
				i++;
			}
			cout<<ans-num<<endl;
			return;
		}
		i++;
	}
}

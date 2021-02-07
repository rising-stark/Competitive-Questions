#include<bits/stdc++.h>
/*#define ll long long int
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
*/
using namespace std;
/*
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
	srand(i*10000);
	int a=1+rand()%((int)1e9);
	int b=1+rand()%((int)1e9);
	int n=1+rand()%((int)1e4);
	cout<<a<<" "<<b<<" "<<n<<endl;
	int m=n;
	while(n--){
		cout<<1+rand()%((int)1e2)<<" ";
	}cout<<endl;
	while(m--){
		cout<<1+rand()%((int)1e2)<<" ";
	}cout<<endl;
}*/
void solve1()
{
	#define ll              long long int
	#define scan(any)       for(auto &i:any) cin>>i;
	#define print(any)      for(auto i:any) cout<<i<<" "; 
	#define endl            '\n'
	#define pb              push_back
	#define vll             vector<ll> 
	#define f(i,x,y)        for(i=x;i<y;i++)
	#define INF             LLONG_MAX
	#define s(x)            sort(x.begin(),x.end())
	#define all(v)          v.begin(),v.end()
	#define p2(n,x)         cout << fixed << setprecision(x) <<n<<endl; 
	#define pll             pair<ll,ll> 
	#define ff              first
	#define ss              second
	#define blt(x)          __builtin_popcount(x)
    ll i,j,k,n,a,b;
    cin>>a>>b>>n;
    vector<vll> v(n,vll(2,0));
    f(i,0,n)
    cin>>v[i][0];
    f(i,0,n)
    cin>>v[i][1];
 
    s(v);
    f(i,0,n)
    {
        if(b<=0)
        {
            cout<<"NO\n";
            return ;
        }
        ll t=ceil((1.0*v[i][1])/a);
        if(v[i][0]*t<=b || v[i][0]*(t-1)<b)
        {
            b-=(v[i][0]*t);
        }
        else
        {
            cout<<"NO\n";
            return ;
 
        }
    }
    cout<<"YES\n";
    
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif
	int t=1000;
	//cout<<t<<endl;
	cin>>t;
	for(int i=0;i<t;i++){
		//cin<<"Case "<<(i)<<" : "
		//genTestCases(i);
		solve1();
	}
	return 0;
}
/*
void solve(){
	ll i, j, a, b, n;
	cin>>a>>b>>n;
	vll arr(n), arr1(n);
	vpll ans(n);
	for(i=0;i<n;i++){
		cin>>ans[i].first;
	}
	for(i=0;i<n;i++){
		cin>>ans[i].second;
	}
	sort(all(ans));
	for(i=0;i<n;i++){
		arr[i]=ans[i].first;
		arr1[i]=ans[i].second;
	}
	for(i=0;i<n;i++){
		ll x=arr[i] * 1LL* ceil(arr1[i]*1.0/a);
		if(x>=b){
			break;
		}else{
			b-=x;
		}
	}
	if(i==n){
		cout<<"YES"<<endl;
		return;
	}
	if(i<n-1){
		cout<<"NO"<<endl;
		return;
	}
	ll x=ceil(b*1.0/arr[i]);
	if(x*a<arr1[i]){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
		return;
	}
}*/
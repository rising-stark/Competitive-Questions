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
#define ff first
#define ss second
#define vpii vector<pair<int, int> >
#define vpll vector<pair<ll, ll> >
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define maxx(a, b, c) max((a), max((b), (c)))
#define minn(a, b, c) min((a), min((b), (c)))
#define dup(x) (x).resize(distance((x).begin(), unique(all(x))))
#define maxn 1<<15
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
inline ll binexp(ll a, ll b, ll m){a%=m;ll res=1;while(b){if(b&1)res=(res*a)%m;a=(a*a)%m;b>>=1;}return res;}
inline string toBase(ll a,ll b=2){string s="";if(!a)return"0";while(a){s=to_string(a%b)+s;a/=b;}return s;}
inline ll digsum(ll n){ll ans=0;while(n){ans+=n%10;n/=10;}return ans;}
inline bool ispow2(ll i){return i && (i & -i) == i;}
inline bool isdigit(char c){if(c>='0' && c<='9')return true;return false;}
inline bool isupper(char c){if(c>='A' && c<='Z')return true;return false;}
inline bool islower(char c){if(c>='a' && c<='z')return true;return false;}
void solve(int);

const int sieveN = maxn;
bitset<sieveN+1> sieve;
vi primes;
void generateSieve(){
	// sieve[i] = 0 means i is prime
	int i, j;
	sieve[0]=sieve[1]=1;
	for(i = 2; i*i <= sieveN; i++){
		for(j = i*i; !sieve[i] && j <= sieveN; j += i){
			sieve[j]=1;
		}
	}
	primes.pb(2);
	for(i=3;i<=sieveN;i+=2){
		if(!sieve[i]){
			primes.pb(i);
		}
	}
}
int isprime(int n){
	if(n<=1)
		return 0;
	return !sieve[n];
}

void compare(){cout.flush();
	ifstream File1, File2;ofstream File3;string line, line2;
	File1.open("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt");
	File2.open("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/stress.txt");
	File3.open("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/stress1.txt");
	if(File1.fail()){ cerr<<"Error opening file output.txt !!"<<endl;return;}
	if(File2.fail()){ cerr<<"Error opening file stress.txt !!"<<endl;return;}
	int diffcount = 0;
	while(!File1.eof() && !File2.eof()){
		getline(File1, line);
		getline(File2, line2);
		if(line == line2){
			File3<<line<<endl;
		}else{
			diffcount++;
			File3<<"Solve: "<<line<<"\tBrute: "<<line2<<"----------------------diff"<<endl;
		}
	}
	File3<<"Total Diff count "<<diffcount<<endl;
	if(File1.eof())
		File3<<"Solve output ends"<<endl;
	if(File2.eof())
		File3<<"Brute output ends"<<endl;
	File1.close();
	File2.close();
	File3.close();
	File1.open("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/stress1.txt");
	File3.open("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt");
	while(!File1.eof()){
		getline(File1, line);
		File3<<line<<endl;
	}
	File1.close();
	File3.close();
}

int initializeRandHK = 0;
void genTestCases(){
	if(initializeRandHK==0){
		ll now = chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
		srand(now);
		initializeRandHK++;
	}
	ll n=1+rand()%((ll)12);
	ll k=1+rand()%((ll)1e5);
	ll m=1+rand()%((ll)1e5);
	cout<<n<<endl;
	//cout<<n<<" "<<k<<endl;
	//cout<<n<<" "<<k<<" "<<m<<endl;
	/*while(n--){
		cout<<rand()%((ll)1e9)<<" ";
	}cout<<endl;*/
}

/*ll dpexp[maxn];
ll bruteexp(int i, vll arr){
	if(i>=arr.size()){
		return 0;
	}
	if(dpexp[i]!=-1){
		return dpexp[i];
	}
	ll a = 0, b = 0;
	a = arr[i] + bruteexp(i+1, arr);
	b = bruteexp(i+1, arr);
	return dpexp[i] = min(a, b);
}*/

void brute(){
	ll i, j, n;
	cin>>n;

	vll arr(n), arr1(n);
	cin>>arr;

	ll ans=1;

	/*memset(dpexp, -1, sizeof(dpexp));
	ans = bruteexp(0, arr);
	//cout<<"output:"<<endl;
	cout<<ans<<endl;
	return;*/


	cout<<ans<<endl;
}
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
	int t=1;
	int stress = t>1;
	//cin>>t;
	//cout<<t<<endl;
	generateSieve();

	if(stress == 1){
		freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "w", stdout);
		for(int i=0;i<t;i++){genTestCases();}cout.flush();
		freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
		freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/stress.txt", "w", stdout);
		for(int i=0;i<t;i++){brute();}cout.flush();
		#ifndef ONLINE_JUDGE
		freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
		freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
		#endif
	}

	while(1){
		int n;
		cin>>n;
		if(!n)
			return 0;
		solve(n);
	}
	if(stress==1){compare();}
	return 0;
}

void solve(int n){
	int c=0;
	for(int i:primes){
		c+=isprime(n-i);
	}
	cout<<c/2+isprime(n/2)<<endl;
}
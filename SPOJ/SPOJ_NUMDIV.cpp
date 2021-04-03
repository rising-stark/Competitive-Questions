#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define maxx(a,b,c) max(a, max(b,c))
#define minn(a,b,c) min(a, min(b,c))
using namespace std;
const int mod=1e9+7;
const int inf = (1<<30);
string toBin(ll a);
void printMat(int arr[], int n);
void printMat(vector<int> arr, int n);
void printMat(vector<vector<int> > arr, int n, int m);
void printMat(vector<int> arr[], int n);
void solve();
//void printMat(int arr[][], int n, int m);
void printMap(unordered_map<int, int> mp);
void printMap(unordered_map<ll, ll> mp);
void printMap(unordered_map<char, int> mp);
void printMap(unordered_map<string, int> mp);
void printMap(map<int, int> mp);
void printMap(map<ll, ll> mp);
void printMap(map<char, int> mp);
void printMap(map<string, int> mp);
void printSet(set<int> s);
void printSet(set<ll> s);
void printSet(set<char> s);
void printSet(set<string> s);
void printSet(unordered_set<int> s);
void printSet(unordered_set<ll> s);
void printSet(unordered_set<char> s);
void printSet(unordered_set<string> s);
string toBin(ll a){
	string s="";
	while(a>0){
		if(a&1){
			s="1"+s;
		}else{
			s="0"+s;
		}
		a>>=1;
	}
	return s;
}
void printMat(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}
void printMat(vector<int> arr, int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}
void printMat(vector<int> arr[], int row, int col){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<arr[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}
void printMat(vector<vector<int> > arr, int row, int col){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<arr[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}
void printMap(unordered_map<int, int> mp){
	unordered_map<int, int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		cout<<it->first<<" -->"<<it->second<<endl;
	}
	cout<<endl;
}
void printMap(unordered_map<ll, ll> mp){
	unordered_map<ll, ll>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		cout<<it->first<<" -->"<<it->second<<endl;
	}
	cout<<endl;
}
void printMap(unordered_map<char, int> mp){
	unordered_map<char, int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		cout<<it->first<<" -->"<<it->second<<endl;
	}
	cout<<endl;
}
void printMap(unordered_map<string, int> mp){
	unordered_map<string, int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		cout<<it->first<<" -->"<<it->second<<endl;
	}
	cout<<endl;
}
void printMap(map<int, int> mp){
	map<int, int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		cout<<it->first<<" -->"<<it->second<<endl;
	}
	cout<<endl;
}
void printMap(map<ll, ll> mp){
	map<ll, ll>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		cout<<it->first<<" -->"<<it->second<<endl;
	}
	cout<<endl;
}
void printMap(map<char, int> mp){
	map<char, int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		cout<<it->first<<" -->"<<it->second<<endl;
	}
	cout<<endl;
}
void printMap(map<string, int> mp){
	map<string, int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		cout<<it->first<<" -->"<<it->second<<endl;
	}
	cout<<endl;
}
void printSet(set<int> s){
	set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		cout<<(*it)<<" ";
	}cout<<endl;
}
void printSet(set<ll> s){
	set<ll>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		cout<<(*it)<<" ";
	}cout<<endl;
}
void printSet(set<char> s){
	set<char>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		cout<<(*it);
	}cout<<endl;
}
void printSet(set<string> s){
	set<string>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		cout<<(*it)<<" ";
	}cout<<endl;
}
void printSet(unordered_set<int> s){
	unordered_set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		cout<<(*it)<<" ";
	}cout<<endl;
}
void printSet(unordered_set<ll> s){
	unordered_set<ll>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		cout<<(*it)<<" ";
	}cout<<endl;
}
void printSet(unordered_set<char> s){
	unordered_set<char>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		cout<<(*it);
	}cout<<endl;
}
void printSet(unordered_set<string> s){
	unordered_set<string>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		cout<<(*it)<<" ";
	}cout<<endl;
}

bitset<1000005> primes;

ll mult(ll a, ll b, ll p){
	//cout<<"Mult a = "<<a<<" b= "<<b<<endl;
	if(a==1){
		return b%p;
	}
	if(a==0){
		return 0;
	}
	if(a&1){
		return ((2*mult(a/2, b, p))%p + b%p)%p;
	}else{
		return (2*mult(a/2, b, p))%p;
	}
}

ll modExp(ll a, ll n, ll p){
	//cout<<"mod exp a = "<<a<<" n= "<<n<<" p= "<<p<<endl;
	ll res=1;
	while(n>0){
		if(n&1){
			res=mult(min(a,res), max(a, res), p)%p;
			//res=(res*a)%p;
		}
		n>>=1;
		a=mult(a, a, p)%p;
	}
	//cout<<"res= "<<res<<endl;
	return res;
}

bool isPrime(ll n){
	if(n==2 || n==3 || n==5 || n==7){
		return true;
	}
	if(n<=1 || n%2==0 || n%3==0 || n%5==0){
		return false;
	}

	ll s=n-1;
	int d=0;
	while(s%2==0){
		d++;
		s/=2;
	}
	ll a;
	//cout<<"Checking Primality for "<<n<<endl;
	//cout<<"s= "<<s<<" d = "<<d <<endl;
	for(int i=0;i<40;i++){
		a=2+rand()%n;
		//cout<<"a = "<<a<<endl;
		ll x=modExp(a, s, n);
		if(x==1 || x==n-1){
			//cout<<"n is maybe prime for this a. Choosing some other a"<<endl;
			continue;
		}
		int flag=0;
		while(s!=(n-1)){
			x=modExp(a, s, n);
			if(x==(n-1)){
				flag=1;
				break;
			}
			s*=2;
		}
		if(flag==0){
			return false;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	//t=1;
	primes[0]=primes[1]=1;
	ll cr=1000001;
	ll sqrtcr=(ll)sqrt(1000001);
	for(ll i=2;i<sqrtcr;i++){
		if(primes[i]==0){//cout<<"i= "<<i<<endl;
			for(ll j=i*i;j<=cr;j+=i){
				primes[j]=1;
			}
		}
	}
	while(t--){
		solve();
	}
	//cout<<isPrime(2920910506223);
	/*string s;
	cin>>s;
	cout<<s.length();*/
	return 0;
}

void solve(){
	int i, j;
	ll n;
	cin>>n;
	if(isPrime(n)){
		cout<<2<<endl;
		return;
	}
	ll cr=1000001;
	int ans=1;
	for(i=2;i<=cr && n>1;i++){
		int count=1;
		while(primes[i]==0 && n%i==0){
			count++;
			n/=i;
		}
		ans*=count;
	}
	//cout<<"n = "<<n<<" div = "<<ans<<endl;
	//solve1(n)
	if(n>1){
		if(isPrime(n)==true){
			ans*=2;
		}else{
			ll sq=(ll)sqrt(n);
			if(isPrime(sq) && (sq*1LL*sq) ==n){
				ans*=3;
			}else{
				ans*=4;
			}
		}
	}
	cout<<ans<<endl;
}

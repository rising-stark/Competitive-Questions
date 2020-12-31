#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int> >
#define vvll vector<vector<ll> >
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pis pair<int, string>
#define psi pair<string, int>
#define ALL(x) x.begin(), x.end()
#define maxx(a,b,c) max(a, max(b,c))
#define minn(a,b,c) min(a, min(b,c))
using namespace std;
const ll mod=1000000007LL;
const int inf = (1<<30);
void solve();
string toBin(ll a);
void printMat(int arr[], int n);
void printMat(vector<int> arr, int n);
void printMat(vector<vector<int> > arr, int n, int m);
void printMat(vector<vector<ll> > arr, int n, int m);
void printMat(vector<int> arr[], int n);
void printMat(vector<ll> arr[], int n);
void printMat(int arr[][2], int n, int m);
void printMat(ll arr[][2], int n, int m);
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
void printMat(vector<vector<ll> > arr, int row, int col){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<arr[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}
void printMat(ll arr[][2], int row, int col){
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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif
	int t=1;
	//scanf("%d", &t);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
void solve(){
	ll i, j, n;
	cin>>n;
	ll arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	ll bit = 60;
	ll dp[n][bit];
	ll p[bit], pmod[bit];
	memset(dp, 0, sizeof dp);
	memset(p, 0, sizeof p);
	memset(pmod, 0, sizeof pmod);
	p[0]=pmod[0]=1;
	for(i=1;i<bit;i++){
		p[i]=p[i-1]*2LL;
		pmod[i]=p[i]%mod;
		//cout<<p[i]<<endl;
	}
	for(i=0;i<bit;i++){
		for(j=0;j<n;j++){
			if(j==0){
				dp[j][i]=(arr[j]&p[i])>0LL;
				continue;
			}
			dp[j][i]=dp[j-1][i]+((arr[j]&p[i])>0LL);
		}
	}
	/*for(i=0;i<n;i++){
		for(j=0;j<bit;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;*/
	ll ans=0;
	for(i=0;i<n;i++){
		ll ans1=0,ans2=0;
		for(j=0;j<bit;j++){
			ll z=pmod[j];
			ll x=dp[i][j];
			if(i>0){
				x=dp[i][j]-dp[i-1][j];
			}
			ll y=dp[n-1][j];
			if(x==1){
				y=n;
				x=(dp[n-1][j]*z)%mod;
			}
			y=(y*z)%mod;
			ans1=(ans1+x)%mod;
			ans2=(ans2+y)%mod;
		}
		ans=(ans+(ans1*ans2)%mod)%mod;
	}
	cout<<ans<<endl;
}

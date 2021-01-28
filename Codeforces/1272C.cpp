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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
	int t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
	cout<<(1.0/(1.0+(10.0*((100-1300)/400.0))));
	return 0;
}
void solve(){
	int i, j, n, k;
	string s;
	cin>>n>>k>>s;
	int freq[26];
	memset(freq, -1, sizeof(freq));
	for(i=0;i<k;i++){
		char c;
		cin>>c;
		freq[c-'a']=0;
	}
	ll sum=0;
	int arr[n];
	memset(arr, 0, sizeof(arr));
	for(i=0;i<n;i++){
		arr[i] = freq[s[i]-'a'];
	}
	//printMat(arr, n);
	j=0;
	for(i=0;i<n;i++){
		if(i>=j){
			while(j<n && arr[j]!=-1){
				j++;
			}
		}
		if(arr[i]==-1){
			j++;
			continue;
		}
		ll x=j-i;
		sum+=(x*(x+1))/2;
		i=j;
		j++;
		//cout<<"i = "<<i<<" "<<endl;
	}
	cout<<sum<<endl;
}

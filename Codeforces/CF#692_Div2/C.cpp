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
const int mod=1e9+7;
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
	int i, j, n, m;
	cin>>n>>m;
	int arr[n]={0};
	set<int> s[4];
	vector<pair<int, int>> v[n];
	for(i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(a==b){
			s[3].insert(a);
			continue;
		}
		a--;
		b--;
		arr[a]++;
		arr[b]++;
		v[a].pb({a,b});
		v[b].pb({a,b});
	}
	for(i=0;i<n;i++){
		s[arr[i]].insert(i);
	}
	int c=0;
	while(s[3].size()!=m){
		c++;
		if(s[1].size()>0){

		}else{
			auto it=s[2].begin();
			s[2].erase(it);
			pair<int, int> temp = v[*it][0];
			temp.
		}
	}
	printMat(arr, n);
}

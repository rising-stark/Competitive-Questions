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
#define all(x) x.begin(), x.end()
#define maxx(a,b,c) max((a), max((b), (c)))
#define minn(a,b,c) min((a), min((b), (c)))
using namespace std;
const ll mod=1e9+7;
const ll inf = (1<<30);
void solve();
template <typename T>
void printarr(T arr, int debug=0){
	if(debug==1){
		cout<<"Printing arr::"<<endl;
	}
	for(auto i:arr){
		cout<<i<<" ";
		//cout<<i.first<<" "<<i.second<<endl;
	}cout<<endl;
}
template <typename T>
void printarr2d(T arr, int debug=0){
	if(debug==1){
		cout<<"Printing arr::"<<endl;
	}
	for(int i=0;i<arr.size();i++){
		for(int j=0;j<arr[i].size();j++){
			cout<<arr[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}
void printgraph(vi arr[], int n, int debug=0){
	if(debug==1){
		cout<<"Printing arr::"<<endl;
	}
	for(int i=0;i<n;i++){
		cout<<i+1<<" --> ";
		for(int j=0;j<arr[i].size();j++){
			cout<<1+arr[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}
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
	//cin>>t;
	for(int i=0;i<t;i++){
		//cin<<"Case "<<(i)<<" : "
		//genTestCases(i);
		solve();
	}
	return 0;
}

vi arr(100001, 0);
vi vis(100001, 0);
int ans=0;
int m=0;
void dfs(vi adj[], int u, int maxc, int curc, int prev){
	if(adj[u].size()==1 && vis[adj[u][0]]==1){
		if(prev==1){
			if(arr[u]==1){
				curc++;
			}else{
				curc=0;
			}
		}else{
			curc=arr[u];
		}
		maxc=max(maxc, curc);
		if(maxc<=m){
			ans++;
		}
		return;
	}
	for(int v:adj[u]){
		if(vis[v]==0){
			vis[v]=1;
			int x=curc;
			int y=maxc;
			if(prev==1){
				if(arr[u]==1){
					curc++;
				}else{
					curc=0;
				}
			}else{
				curc=arr[u];
			}
			maxc=max(maxc, curc);
			dfs(adj, v, maxc, curc, arr[u]);
			curc=x;
			maxc=y;
		}
	}
}
void solve(){
	int i, j, n;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	vi adj[n];
	for(i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	vis[0]=1;
	dfs(adj, 0, 0, 0, 0);
	cout<<ans<<endl;
}

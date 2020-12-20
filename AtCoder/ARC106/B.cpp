#include<bits/stdc++.h>
#define ll long long int
#define MAX 300000
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

int main(){
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif*/
	int t=1;
	//scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}
ll a[MAX], b[MAX];
bool vis[MAX];
ll dfs(vector<int> adj[], int s){
	vis[s]=true;
	//cout<<s<<endl;
	int i;
	ll ans=0;
	for(i=0;i<adj[s].size();i++){
		int x=adj[s][i];
		if(vis[x]==false){
			//vis[s]=true;
			ans+=dfs(adj, x);
		}
	}
	return ans-(a[s]-b[s]);
}
void solve(){
	int i, j, n, m;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		cin>>b[i];
	}
	vector<int> adj[n];
	for(i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i=0;i<n;i++){
		if(vis[i]==0){
			if(dfs(adj, i)!=0){
				cout<<"No"<<endl;
				return;
			}
		}
	}
	cout<<"Yes"<<endl;
}

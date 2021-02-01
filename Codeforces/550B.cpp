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
		cout<<i<<" --> ";
		for(int j=0;j<arr[i].size();j++){
			cout<<arr[i][j]<<" ";
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
int n, l, r, x, ans=0;
void count(vi arr, int i, vi cur){
	/*cout<<"i = "<<i<<" ans = "<<ans<<endl;
	printarr(cur);
	cout<<endl;*/
	if(i==n){
		if(cur.size()>=2){
			int sum=0, mi=INT_MAX, ma=INT_MIN;
			for(int j:cur){
				sum+=j;
				mi=min(mi, j);
				ma=max(ma, j);
			}
			if(sum>=l && sum<=r && ma-mi >=x){
				ans++;
			}
		}
		return;
	}
	count(arr, i+1, cur);
	cur.pb(arr[i]);
	count(arr, i+1, cur);
}
void solve(){
	int i;
	cin>>n>>l>>r>>x;
	vi arr(n, 0);
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	vi cur;
	count(arr, 0, cur);
	cout<<ans<<endl;
}

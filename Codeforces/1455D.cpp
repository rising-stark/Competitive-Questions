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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
void solve(){
	int i, j, n, x;
	cin>>n>>x;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans = 0, mm = arr[0];
	for(i = 1; i < n; i++){
		if(arr[i] >= arr[i-1]){
			mm = max(mm, arr[i]);
			continue;
		}
		if(arr[i] < x || mm <= x){
			cout<<-1<<endl;
			return;
		}
		int p = upper_bound(arr, arr + i, x) - arr;
		for(int j = p; j<i;j++){
			if(arr[j]>x){
				ans++;
				swap(arr[j], x);
			}
		}
		if(arr[i] < arr[i-1]){
			cout<<-1<<endl;
			return;
		}
		//cout<<"p = "<<p<<" "<<"i = "<<i<<" ans = "<<ans<<" x = "<<x<<endl;
		mm = arr[i];
	}
	cout<<ans<<endl;
}

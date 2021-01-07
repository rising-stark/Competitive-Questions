#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int> >
#define vvll vector<vector<ll> >
#define pii pair<int, int>
#define pll pair<ll, ll>
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
	for(auto &i:arr){
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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r", stdin);
	freopen("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w", stdout);
	#endif
	int t=1;
	cin>>t;
	for(int i=0;i<t;i++){
		//cin<<"Case "<<(i)<<" : "
		solve();
	}
	return 0;
}

void solve(){
	int i, j, n;
	cin>>n;
	vi arr(n, 0);
	int a=0, b=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
		a+=arr[i]==1;
		b+=arr[i]==2;
	}
	int sum=0;
	sum=a+2*b;
	if(sum&1){
		cout<<"NO"<<endl;
		return;
	}
	if(a==0 || b==0){
		if(max(a,b)%2==0){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		return;
	}
	sum/=2;
	for(i=1;i<=b;i++){
		if(sum-(2*i)<=a){
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
	return;
}
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
	int i, j, k, n;
	cin>>n;
	vll arr(n, 0);
	ll a=0, b=0;
	vll even, odd;
	for(i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]&1){
			odd.pb(arr[i]);
		}else{
			even.pb(arr[i]);
		}
	}
	sort(all(even), greater<ll>());
	sort(all(odd), greater<ll>());
	i=0;j=0;k=0;
	while(i<even.size() && j<odd.size()){
		if(k%2==0){ //Alice's turn
			if(even[i]>odd[j]){
				a+=even[i];
				i++;
			}else{
				j++;
			}
		}else{
			if(even[i]>odd[j]){
				i++;
			}else{
				b+=odd[j];
				j++;
			}
		}
		k++;
	}
	while(i<even.size()){
		if(k%2==0){
			a+=even[i];
		}
		i++;
		k++;
	}
	while(j<odd.size()){
		if(k%2!=0){
			b+=odd[j];
		}
		j++;
		k++;
	}
	if(a>b){
		cout<<"Alice"<<endl;
	}else if(a<b){
		cout<<"Bob"<<endl;
	}else{
		cout<<"Tie"<<endl;
	}
}
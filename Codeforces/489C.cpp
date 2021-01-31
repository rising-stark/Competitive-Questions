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
string getM(int m, int sum){
	string s="";
	int x=sum/9;
	m-=x;
	sum-=x*9;
	while(x--){
		s+="9";
	}
	if(sum>0){
		s+=to_string(sum);
		m--;
	}
	while(m--){
		s+="0";
	}
	return s;
}
void solve(){
	int i, j, m, s;
	cin>>m>>s;
	string minans, maxans="";
	if(m==1 && s<10){
		cout<<s<<" "<<s<<endl;
		return;
	}
	if(s==0 || s>(9*m)){
		cout<<-1<<" "<<-1<<endl;
		return;
	}
	maxans=getM(m,s);
	minans=maxans;
	reverse(all(minans));
	if(minans[0]=='0'){
		i=0;
		while(minans[i]=='0'){
			i++;
		}
		int x=minans[i]-'0';
		x--;
		minans[i]=x+'0';
		minans[0]='1';
	}
	cout<<minans<<" "<<maxans<<endl;
}

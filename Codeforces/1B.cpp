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
bool contain(string s){
	int i, n;
	n=s.length();
	for(i=0;i<n;i++){
		if(s[i]=='C'){
			if(s[0]=='R' && i>1 && isdigit(s[i-1]) && isdigit(s[i+1])){
				return true;
			}
		}
	}
	return false;
}
void solve(){
	int r, c, n;
	string s;
	cin>>s;
	n=(int)s.size();
	if(s[0]=='R' && isdigit(s[1]) && contain(s)){
		string row = "", col="";
		int i=1;
		for(i=1;i<n;i++){
			char p=s[i];
			if(p=='C'){
				break;
			}
			row+=p;
		}
		i++;
		while(i<n){
			col+=s[i];
			i++;
		}
		string ans="";
		c=stoi(col);
		//cout<<row<<" "<<col<<" "<<c<<endl;
		while(c>0){
			char a;
			if(c%26==0){
				c-=26;
				a='Z';
			}else{
				a = (char)((c%26)+64);
			}
			//cout<<a<<endl;
			ans=a+ans;
			c/=26;
		}

		cout<<ans+row<<endl;
	}else{
		string row="";
		int i=n-1;
		while(isdigit(s[i])){
			row=s[i]+row;
			i--;
		}
		int ans=0, j=0;
		while(i>=0){
			ans+=pow(26,j)*(s[i]-64);
			i--;
			j++;
		}
		cout<<"R"<<row<<"C"<<ans<<endl;
	}
}

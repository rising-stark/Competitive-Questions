#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod=1e9+7;
const int inf = (1<<30);
string toBin(ll a);
void printMat(int arr[], int n);
void printMat(vector<int> arr, int n);
void printMat(vector<vector<int> > arr, int n, int m);
void printMat(vector<int> arr[], int n);
//void printMat(int arr[][], int n, int m);

void solve(){
	int i, j, n;
	cin>>n;
	int dp[n+1], dp1[n+1];
	memset(dp, -1, sizeof(dp));
	memset(dp1, -1, sizeof(dp1));
	for(i=1;i<=n;i++){
		int x;
		cin>>x;
		bool flag=false;
		for(j=0;j<x;j++){
			int a;
			cin>>a;
			if(dp[a]==-1 && flag==false){
				dp[a]=i;
				flag=true;
				dp1[i]=1;
			}
		}
	}
	/*printMat(dp, n+1);
	printMat(dp1, n+1);*/
	int improv=-1;
	for(i=1;i<=n;i++){
		if(dp1[i]==-1){
			improv=i;
			break;
		}
	}int improv1=-1;
	for(i=1;i<=n;i++){
		if(dp[i]==-1){
			improv1=i;
			break;
		}
	}
	if(improv==-1 && improv1==-1){
		cout<<"OPTIMAL"<<endl;
	}else{
		cout<<"IMPROVE"<<endl;
		cout<<improv<<" "<<improv1<<endl;
	}
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
	cin>>t;
	//t=1;
	while(t--){
		solve();
	}
	return 0;
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
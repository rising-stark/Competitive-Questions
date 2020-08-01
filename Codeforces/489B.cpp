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
	int i, j, n, m;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>m;
	int arr1[m];
	for(i=0;i<m;i++){
		cin>>arr1[i];
	}
	sort(arr, arr + n);
	sort(arr1, arr1 + m);
	int dp[m+1][n+1];
	memset(dp, 0, sizeof(dp));
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(abs(arr1[i-1]-arr[j-1])<=1){
				dp[i][j]=max(1+dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
			}
			else{
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout<<dp[m][n];
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
	//cin>>t;
	t=1;
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
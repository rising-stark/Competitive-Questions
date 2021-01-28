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
	vector<int> arr;
	for(i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
		//cout<<x<<endl;
	}
	vector<int> dp;
	dp.push_back(arr[0]);
	ll sum=0;
	for(i=1, j=1;i<n;i++){
		if((dp[j-1]<0 && arr[i]<0) || (dp[j-1]>0 && arr[i]>0)){
			dp[j-1]=max(dp[j-1], arr[i]);
		}else{
			dp.push_back(arr[i]);
			j++;
		}
	}
	for(i=0;i<dp.size();i++){
		sum+=dp[i];
	}
	cout<<sum<<endl;
	//cout<<"Hello"<<endl;
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
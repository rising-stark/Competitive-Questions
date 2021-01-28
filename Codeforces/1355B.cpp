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

bool check (int arr[], int n, int size){
	int i, j;
	for(i=0;i<n;i++){
		int c=0;
		int ma=-1;
		while(i<n){
			ma=max(ma, arr[i]);
			if(ma >c){
				c++;
				//cout<<" c ="<<c<<endl;
				i++;
			}
			if(ma==c){
				i--;
				break;
			}
		}
		if(i<n){
			size--;
		}
		//cout<<" size = "<<size;
	}
	return size<=0;
}

void solve(){
	int i, j, n;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	// This can be done in nlogn using the binary searching
	// the maximum group size in logn and then checking the feasibility of that group in O(n).
	sort(arr, arr + n);
	int low=0, high=n;
	int ans=1;
	while(low<=high){
		int mid = low+((high-low)/2);
		//cout<<"mid = "<<mid;
		if(check(arr, n, mid)==true){
			ans=max(ans, mid);
			low=mid+1;
			//cout<<" low = "<<low<<endl;
		}
		else{
			high=mid-1;
			//cout<<" high ="<<high<<endl;
		}
	}
	cout<<ans<<endl;
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
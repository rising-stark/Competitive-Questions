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
bool check(int freq[], int n){
	for(int i=0;i<n;i++){
		if(freq[i]==0){
			return false;
		}
	}
	return true;
}
void solve(){
	int i, j, n;
	string s;
	cin>>s;
	n=s.length();
	int freq[3]={0};
	int ans=n+1;
	for(i=j=0;i<n;i++){
		while(j<n){
			bool flag=true;
			freq[s[j]-'1']++;
			for(int k=0;k<3;k++){
				if(freq[k]==0){
					flag=false;
					break;
				}
			}
			j++;
			if(flag==true){
				break;
			}
		}
		while(i<j && check(freq, 3)){
			freq[s[i]-'1']--;
			ans=min(ans, j-i);
			if(check(freq, 3)==false){
				break;
			}
			i++;
		}
	}
	cout<<(ans==(n+1)?0:ans)<<endl;
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
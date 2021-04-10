#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod=1e9+7;
void solve(){
	int i, j, n, m;
	cin>>n;
	m=3;
	int arr[n][3];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	for(i=1;i<n;i++){
		for(j=0;j<m;j++){
			int ma=0;
			for(int k=0;k<m;k++){
				if(k==j){
					continue;
				}
				ma=max(ma, arr[i-1][k]);
			}
			arr[i][j]+=ma;
		}
	}
	cout<<*max_element(arr[n-1], arr[n-1] + m)<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
	solve();
	return 0;
}
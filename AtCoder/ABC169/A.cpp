#include <iostream>
#define ll long long int
const ll inf = 1e18;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
  int n;
  cin>>n;
  ll arr[n];
  ll p=1;
  int c=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]==0){
    	c++;
    }
  }
  if(c>0){
  	cout<<0<<endl;
  	return 0;
  }
  ll q=1;
  for(int i=0;i<n;i++){
    q=p*arr[i];
    if(q>inf || q<0){
      cout<<-1<<endl;
      return 0;
    }
    p=q;
    cout<<p<<endl;
  }
  cout<<p<<endl;
  return 0;
}
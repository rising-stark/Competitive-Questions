#include <iostream>
#include <bitset>
#define ll long long int
using namespace std;

int lessn(ll n, int arr[], int k){
	bitset<1000000> b;
	int i,j;
	for(i=0;i<k;i++){
		for(j=0;(j*arr[i])<n;j++){
			b[j*arr[i]]=1;
		}
	}
	return n-b.count();
}

int main() {
	ll n;
	int i,k;
	cin>>n>>k;
	int arr[k];
	for(i=0;i<k;i++){
		cin>>arr[i];
	}
	if(n<100000001){
		cout<<lessn(n, arr, k)<<endl;
	}else{
		//cout<<more(n, arr, k)<<endl;
	}
	return 0;
}
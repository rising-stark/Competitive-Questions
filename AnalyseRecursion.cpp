#include <bits/stdc++.h>
using namespace std;

void tab(int k){
    for(int i=0;i<k;i++){
        cout<<"\t";
    }
}
int coins(int arr[], int n, int x, int v[]){
	int l=1;
	int r=1;
	int i;
	for(i=x-1;i>=0;i--){
		if(v[i]==0){
			l=arr[i];
			break;
		}
	}

	for(i=x+1;i<n;i++){
		if(v[i]==0){
			r=arr[i];
			break;
		}
	}
	return(l*r*arr[x]);
}

void fun(int v[], int k, int i, int res, int c, int n){
	tab(n-k); cout<<"Current index of loop = "<<i<<endl;
	tab(n-k); cout<<"Balloons left = "<<k<<endl;
	tab(n-k); cout<<"Coins collected = "<<c<<endl;
	tab(n-k); cout<<"Recursive result = "<<res<<endl;
	tab(n-k); cout<<"Visited array "<<endl;
	tab(n-k); for(i=0;i<n;i++){
		cout<<v[i]<<" ";
	}cout<<endl<<endl;
}

int burst(int arr[], int n, int v[], int k){
	if(k==0){
		return 0;
	}
	int i,res,c=0;
	res=INT_MIN;
	for(i=0;i<n;i++){
		fun(v, k, i, res, c, n);
		if(v[i]==0){
			v[i]=1;
			c=coins(arr, n, i, v);
			int p=burst(arr, n, v, k-1);
			fun(v, k, i, p, c, n);
			res=max(res,c+p);
			v[i]=0;
		}
	}
	return res;
}

int main() {
	int arr[]={3,1,5,8};
	int v[]={0,0,0,0};
	cout<<burst(arr, 4, v, 4);
	return 0;
}

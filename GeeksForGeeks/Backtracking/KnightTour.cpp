```

#include <iostream>
#include <cstring>
#include <utility>
#include <stack>
#define MAX 6
using namespace std;

void printStack(stack<pair<int, int> > s){
	if(s.empty()){
		return;
	}
	if(s.size()==1){
        cout<<"\nPrinting Stack:\n";
		cout<<s.top().first<< " "<<s.top().second<<endl;
		return;
	}
	pair<int, int> p;
	p=s.top();
	s.pop();
	printStack(s);
	cout<<p.first<<" "<<p.second<<endl;
}

void printMatrix(int dp[][MAX], int res){
	int i,j,n;
	n=MAX;
	cout<<"\nPrinting Matrix for path "<<res<<":\n";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}

pair<int, int> nextMove(pair<int, int> p, int i, int dp[][MAX]){
	int a[]={2, 1, -1, -2, -2, -1, 1, 2};
	int b[]={1, 2, 2, 1, -1, -2, -2, -1};
	int x,y,n;
	n=MAX;
	x=p.first+a[i];
	y=p.second+b[i];
	if(0<=x && x<=n-1 && 0<=y && y<=n-1 && dp[x][y]==0){
		return make_pair(x,y);
	}
	return make_pair(-1, -1);
}

void kn(stack<pair<int, int> > s, int c, int dp[][MAX], int &res){
	if(c==(MAX*MAX)){
		res++;
		//printStack(s);
		//printMatrix(dp,res);
		pair<int, int> p;
        p=s.top();
		dp[p.first][p.second]=0;
		return;
	}
	/*if(res==10){
        return;
	}*/
	int i;
	pair<int, int> p;
	p=s.top();
	/*if(c==24){
        cout<<"here";
	}*/
    //printStack(s);
    //if (res==1) {printMatrix(dp, res);}
	for(i=0;i<8;i++){
		pair<int, int> q=nextMove(p, i, dp);
		if(q.first!=-1){
			s.push(q);
			dp[q.first][q.second]=c+1;
			kn(s, c+1, dp, res);
		}
	}
	dp[p.first][p.second]=0;
}

int main() {
	int i,j,n,c=0;
	n=MAX;
	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            int res=0;
            int dp[MAX][MAX];
            memset(dp, 0, sizeof(dp));
            stack<pair<int, int> > s;
            s.push(make_pair(i,j));
            dp[i][j]=1;
            kn(s, 1, dp, res);
            c+=res;
            cout<<"Cumulative= "<<c<<" .";
            cout<<"Individual= "<<res<<" Paths for i, j ="<<i<<" ,"<<j<<endl;
        }
	}
	cout<<"Total paths "<<c<<endl;
	return 0;
}


```

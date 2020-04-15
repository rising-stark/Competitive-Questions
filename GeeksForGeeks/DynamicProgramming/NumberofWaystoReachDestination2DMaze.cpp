https://practice.geeksforgeeks.org/problems/special-matrix/0

Given a maze with obstacles, count number of paths to reach rightmost-bottommost cell from topmost-leftmost cell.
A cell in given maze has value -1 if it is a blockage or dead end, else 0.

From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only.

Examples:



Input: maze[R][C] =  {{0,  0, 0, 0},
                      {0, -1, 0, 0},
                      {-1, 0, 0, 0},
                      {0,  0, 0, 0}};
Output: 4

```
// Includes top-down as well as bottom-up approach

#include <iostream>
#include <cstring>
#define MOD 1000000007
#define ll long long int

using namespace std;

/*ll ways(int arr[][MAX], int i, int j, int dp[][MAX]){
    if(i<0 || j<0){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    if(arr[i][j]==-1){
        return 0;
    }
    if(dp[i][j]==-1){
        ll a=ways(arr, i-1, j, dp)%MOD;
        ll b=ways(arr, i, j-1, dp)%MOD;
        dp[i][j]=(a+b)%MOD;
    }
    return dp[i][j];
}*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k,i,j;
        cin>>n>>m>>k;
        int arr[n][m];
        memset(arr, 0 , sizeof(arr));
        for(i=0;i < k;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            arr[x][y]=-1;
        }
        /*for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;*/
        
        for(i=0;i<n;i++){
            if(arr[i][0]==0){
                arr[i][0]=1;
            }else{
                while(i<n){
                    arr[i][0]=-1;
                    i++;
                }
            }
        }
        for(i=1;i<m;i++){
            if(arr[0][i]==0){
                arr[0][i]=1;
            }else{
                while(i<m){
                    arr[0][i]=-1;
                    i++;
                }
            }
        }
        /*for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;*/
        
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(arr[i][j]==-1 || (arr[i-1][j]==-1 && arr[i][j-1]==-1)){
                    arr[i][j]=-1;
                }else{
                    ll a=0;
                    ll b=0;
                    if(arr[i-1][j]!=-1){
                        a=arr[i-1][j];
                    }
                    if(arr[i][j-1]!=-1){
                        b=arr[i][j-1];
                    }
                    arr[i][j]=(int)((a+b)%MOD);
                }
            }
        }/*
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;*/
        if(arr[n-1][m-1]==-1){
            cout<<0<<endl;
        }else{
            cout<<arr[n-1][m-1]<<endl;
        }
    }
    return 0;
}

```

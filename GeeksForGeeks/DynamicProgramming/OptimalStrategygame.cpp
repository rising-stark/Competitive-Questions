https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0

Optimal Strategy For A Game
You are given an array A of size N. The array contains integers and is of even length.
The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amouint of money you can win if you go first.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input.
The first line contains N denoting the size of the array. The second line contains N elements of the array.

Output:
For each testcase, in a new line, print the maximum amout.

Constraints:
1 <= T <= 100
2 <= N <= 100
1 <= Ai <= 106

Examples:
Input:
2
4
5 3 7 10
4
8 15 3 7
Output:
15
22

Explanation:
Testcase1: The user collects maximum value as 15(10 + 5)
Testcase2: The user collects maximum value as 22(7 + 15)

```
#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;
int game(int arr[], int dp[][MAX], int i, int j, bool t){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int a=0,b=0;
    a=game(arr, dp, i+1, j, !t);
    b=game(arr, dp, i, j-1, !t);
    if(t){
        dp[i][j]=max(a+arr[i], b+arr[j]);
    }else{
        dp[i][j]=min(a,b);
    }
    return dp[i][j];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int i,j,n;
        cin>>n;
        int arr[n];
        int dp[n][MAX];
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        memset(dp, -1, sizeof(dp));
        cout<<game(arr, dp, 0, n-1, true)<<endl;
    }
    return 0;
}
```

https://leetcode.com/problems/knight-dialer/

A chess knight can move as indicated in the chess diagram below:

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.
Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, output the answer modulo 10^9 + 7.

Example 1:
Input: 1
Output: 10

Example 2:
Input: 2
Output: 20

Example 3:
Input: 3
Output: 46

Note:
1 <= N <= 5000

// The below code includes both top-down recursion as well as bottom-up iterative solution
#define mod 1000000007
#define MAX 500000
class Solution {
public:
    /* Top Down Approach giving TLE
    long long int kn(int n, int i, int j, long long int dp[][3][MAX]){
        if((i<0 || j<0 || i>3 || j>2) || (i==3 && j==0) || (i==3 && j==2)) {
            return 0;
        }
        if(dp[i][j][n]!=-1){
            return dp[i][j][n];
        }
        int a[]={-2, -2, -1, 1, 2, 2, 1, -1};
        int b[]={-1, 1, 2, 2, 1, -1, -2, -2};
        long long int x=0;
        for(int k=0;k<8;k++){
            x=(x+kn(n-1, i+a[k], j+b[k], dp))%mod;
        }
        dp[i][j][n]=x;
        return x;
    }
    int knightDialer(int n) {
        long long int res=0;
        long long int dp[4][3][MAX];
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                dp[i][j][0]=1;
            }
        }
        dp[3][1][0]=1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                res=(res + (kn(n-1, i, j, dp))%mod)%mod;
            }
        }
        res=(res + (kn(n-1, 3, 1, dp))%mod)%mod;
        return (int)res;
    }*/
    int knightDialer(int n) {
        int i,j,k;
        vector<vector<int> > arr;
        arr={
            {4, 6},
            {8, 6},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        };
        long long int dp[10][n];
        memset(dp, 0, sizeof(dp));
        for(i=0;i<10;i++){
            dp[i][0]=1;
        }
        for(i=1;i<n;i++){
            for(j=0;j<10;j++){
                for(k=0;k<((int)arr[j].size());k++){
                    dp[j][i]=(dp[arr[j][k]][i-1] + dp[j][i])%mod;
                }
            }
        }
        for(i=1;i<10;i++){
            dp[i][n-1]=(dp[i][n-1] + dp[i-1][n-1])%mod;
        }
        return dp[9][n-1];
    }
};

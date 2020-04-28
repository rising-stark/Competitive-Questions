https://www.spoj.com/problems/BADXOR/

BADXOR - Bad XOR
Time Limit: 1s

You are given an array A of N elements. Also you are given another array B of M elements.
Any subset (i1, i2, i3, …., ip ) is bad IFF ( Ai1 ⊕ Ai2 ⊕ …. ⊕ Aip ) equals any value of B.
⊕ means Bitwise XOR, which can be found with ^ syntax in popular programming languages.
Now your job is to find the number of good subsets. Empty Subset has XOR value of 0.

Input
The first line of input denotes the number of test cases T (1 <= T <= 20).
The first line of each test case contains two integers N and M ( 0 <= N, M <= 1000).
The next line contains N integers of the array A (0 <= Ai <=1000).
The next line contains M integers of the array B (0 <= Bi <=1000).
You can assume that each element of array B will be unique.  

Output

For each case, print the case number and the total numbers of good subsets in a line.
As the result can be very big, output it modulo 100000007.

Sample Input
2
2 3
1 2
0 1 2
1 3
1
0 1 2

Sample Output
Case 1: 1
Case 2: 0

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <unordered_set>
#include <algorithm>
#define mod 100000007
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int i,j,m,n,c=0;
		scanf("%d %d", &n, &m);
		int arr[n];
		unordered_set<int> s;
		int dp[n+1][1024];
		memset(dp, 0, sizepf(dp));
		for(i=0;i<n;i++){
			scanf("%d", &arr[i]);
		}
		for(i=0;i<m;i++){
			int x;
			scanf("%d", &x);
			s.insert(x);
		}
		sort(a, a + n);
		dp[0][0]=1;
		dp[1][0]=1+(arr[0]==0);
		for(i=2;i<=n;i++){
			dp[i][0]=dp[i-1][0]+(arr[i-1]==arr[i-2]);
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=1023;j++){
				dp[i][j]=(dp[i-1][j]+dp[i-1][j^arr[i-1]])%mod;
			}
		}
		for(i=0;i<1024;i++){
			if(s.find(i)==s.end()){
				c=(c+dp[n][i])%mod;
			}
		}
		printf("%d ", c);
	}
	return 0;
}

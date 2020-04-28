https://www.spoj.com/problems/ADASEQEN/

ADASEQEN - Ada and Subsequence
Ada the Ladybug has two string which she wants to give to her friends.
As she doesn't want to distinguish between them, she wants to use only some common subsequence.
Firstly she wanted to simply use the longest common subsequence but then she realized it wouldn't be kosher.

She assigned a positive value to each letter. Now she wants to find the most expensive subsequence.

Input
The first line of each test-case will contain two integers 1 ≤ N, M ≤ 2000, the length of each subsequence.
The next line will contain 26 integers (1 ≤ Pi ≤ 105), the price of each letter.
The next line will contain string of length N consisting of lowercase english alphabet.
The next line will contain string of length M consisting of lowercase english alphabet.

Output
For each test-case, print the cost of the most expensive common subsequence.

Example Input
4 4
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
abcd
dbca
Example Output
2

Example Input
3 3
1 7 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
baa
aab
Example Output
7

Example Input
4 5
1 4 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 6
zbbz
bbzbb
Example Output
14

Example Input
3 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
abc
def
Example Output
0

#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int main() {
	int i,j, n,m;
	string s1,s2;
	cin>>n>>m;
	int freq[26];
	for(i=0;i<26;i++){
		cin>>freq[i];
	}
	cin>>s1>>s2;
	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=freq[s1[i-1]-'a'] +dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}

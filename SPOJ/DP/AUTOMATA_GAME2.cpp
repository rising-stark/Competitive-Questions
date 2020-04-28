https://www.spoj.com/problems/AUTOMATA/

AUTOMATA - GAME2
Bob is playing Hide and Seek with alphabets and he is amazed by the properties of '?' and '*' in the language.
He is given a language 'L'. He has to check whether the given string 'S' is present in the language 'L'.
He needs your help. Print "Yes" if S is present in L , else print "No".
Definition for L :

L consists of 28 characters , a-z and '?' and '*'
? denotes zero or 1 character(s).
* denotes zero or any number of characters.

Example :
String "adb" is present in language L = {a?b}
String "adb" is present in language L ={a*b}
String "ab" is present in language L = {a?*b*}

Input
First line of input consists of T (T<=50).
Every test case consists of two strings, first line consists of 'L' and second line consists of 'S'.
L consists characters among the 28 characters 'a'-'z' , '?' , '*' only.
S consists of only lower case alphabets.


Output
Print "Yes" if String 'S' is present in language 'L', else print "No".

Example
Input:
5
a?b
acb
a?b
abbb
a*b
abbbb
a*b
asbdfuisdhfsbdfsdfb
abb
bb

Output:
Yes
No
Yes
Yes
No

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		string s1,s2;
		cin>>s2>>s1;
		int i,j,m,n;
		m=s1.length();
		n=s2.length();
		int dp[m+1][n+1];
		memset(dp, 0, sizeof(dp));
		dp[0][0]=1;
		for(i=1;i<=n;i++){
			if(s2[i-1]=='?' || s2[i-1]=='*'){
				dp[0][i]=dp[0][i-1];
			}
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(s2[j-1]==s1[i-1]){
					dp[i][j]=dp[i-1][j-1];
				}else if(s2[j-1]=='?'){
					dp[i][j]=dp[i-1][j-1] || dp[i][j-1];
				}else if(s2[j-1]=='*'){
					dp[i][j]=dp[i-1][j] || dp[i][j-1];
				}
			}
		}
		if(dp[m][n]==1){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}

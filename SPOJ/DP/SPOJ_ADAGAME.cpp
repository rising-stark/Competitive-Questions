https://www.spoj.com/problems/ADAGAME/

ADAGAME - Ada and Game
Ada the Ladybug is playing Game of Digits against her friend Velvet Mite Vinit.
The game is played in following manner: At first, there is a four-digit number and a number of moves.
Both Ada and Vinit take turns alternately (beginning with Ada).
Both of them must increase ANY digit of the number, but if the digit was 9 it will become 0.

For example number 3590 can be expanded to: 4590,3690,3500 or 3591.
If after all turns the number is greater than the original number, Ada wins - otherwise Vinit is the winner.
Both of them play optimaly - can you decide who is the winner?

PS: It is possible, that Ada will have one more turn (if number of turns is odd)

Input
First line of input will consist T ≤ 200 number of test-cases.
Each testcase will consist of four digit number 0 ≤ N < 104 [the original number] and 0 ≤ M ≤ 100 [the number of turns].

Output
For each test-case, print the name of winner ("Ada" or "Vinit").

Example Input
5
0000 0
5566 3
3333 10
9999 9
1234 30

Example Output
Vinit
Ada
Ada
Vinit
Ada

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string getnum(string s, int i){
		if(s[i]=='9'){
			s[i]='0';
		}
		else{
			s[i]++;
		}
		return s;
}

int fun(int dp[][101], int m, string cur, string num, int i){
	if(m==0){
		if(num<=cur){
			return 0;
		}return 1;
	}
	int z=stoi(num);
	if(dp[z][m]!=-1){
		return dp[z][m];
	}
	int a=0,b=0,c=0,d=0;
	a=fun(dp, m-1, cur, getnum(num, 0), !i);
	b=fun(dp, m-1, cur, getnum(num, 1), !i);
	c=fun(dp, m-1, cur, getnum(num, 2), !i);
	d=fun(dp, m-1, cur, getnum(num, 3), !i);
	if(i==0){
		dp[z][m]=a || b || c || d;
	}else{
		dp[z][m]=a && b && c && d;
	}
	return dp[z][m];
}

int main() {
	int t;
	scanf("%d", &t);
	int dp[10000][101];
	while(t--){
		int m;
		string num;
		memset(dp, -1, sizeof(dp));
		cin>>num;
		scanf("%d", &m);
		printf("%s\n",(fun(dp, m, num, num, 0)==0 ?"Vinit":"Ada"));
	}
	return 0;
}

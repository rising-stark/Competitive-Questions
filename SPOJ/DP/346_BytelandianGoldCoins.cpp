https://www.spoj.com/problems/COINS/

COINS - Bytelandian gold coins
In Byteland they have a very strange monetary system.
Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4.
But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.
You have one gold coin. What is the maximum amount of American dollars you can get for it?

Input
The input will contain several test cases (not more than 10). Each testcase is a single line with a number n, 0 <= n <= 1 000 000 000.
It is the number written on your coin.

Output
For each test case output a single line, containing the maximum amount of American dollars you can make.

Example
Input:
12
2

Output:
13
2
You can change 12 into 6, 4 and 3, and then change these into $6+$4+$3 = $13.
If you try changing the coin 2 into 3 smaller coins, you will get 1, 0 and 0, and later you can get no more than $1 out of them.
It is better just to change the 2 coin directly into $2.

#include <iostream>
#include <cstring>
#define ll long long int
#define MAX 1000001
using namespace std;

ll doll(ll n, ll dp[]){
	if(n<=4){
		return n;
	}
	if(n<1000000 && dp[n]!=-1){
		return dp[n];
	}
	ll a=0,b=0,c=0;
	a=doll(n/2, dp);
	b=doll(n/3, dp);
	c=doll(n/4, dp);
	if(n<1000000){
		dp[n]= max(n, (a+b+c));
	}
	
	return max(n, (a+b+c));;
}

int main() {
	ll n;
	while(cin>>n){
		ll dp[MAX];
		memset(dp, -1, sizeof(dp));
		cout<<doll(n, dp)<<endl;
	}
	return 0;
}

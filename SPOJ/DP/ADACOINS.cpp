https://www.spoj.com/problems/ADACOINS/

ADACOINS - Ada and Coins
Ada the Ladybug has several coins in her wallet.
She is wondering, how many different values [sum of some subset of coins] is she able to make (in given range).

Input
The first line contains two integer numbers 1 ≤ N ≤ 104, 1 ≤ Q ≤ 5*105, the number of coins and number of queries.

The next line contains N integer numbers 1 ≤ Ai ≤ 105, the values of coins in Ada's wallet.

Afterward, Q lines follow, each containing two integers 1≤ B≤ E≤ 105, beginning and end of range, for which ada wants to know the answer

Output
For each query, output the number of distinct values Ada can generate in given range.

Example Input
10 10
1 2 2 3 5 30 31 90 100 100
1 1
1 5
3 6
2 9
30 100
1 10000
30 32
5 12
9 29
190 220

Example Output
1
5
4
8
40
231
3
8
5
25

#include <iostream>
#include <stdio.h>
#include <bitset>
using namespace std;
int main(){
    bitset<100001> posi;
    int i,n,q,s[100001]={0};
    scanf("%d %d", &n, &q);
    posi[0] = 1;
    for(i=0;i<n;i++){
    	int x;
    	scanf("%d", &x);
    	posi |=posi<<x;
    }
    //cout<<posi<<endl;
    for(i=1;i<=100001;i++){
    	s[i]=s[i-1]+posi[i];
    }
    while(q--){
    	int a,b;
    	scanf("%d %d", &a,&b);
    	printf("%d\n", (s[b]-s[a-1]));
    }
}

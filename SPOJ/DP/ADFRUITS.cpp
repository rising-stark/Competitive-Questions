https://www.spoj.com/problems/ADFRUITS/

ADFRUITS - Advanced Fruits
The company "21st Century Fruits" has specialized in creating new sorts of fruits by transferring genes from one fruit into the genome
of another one. Most times this method doesn't work, but sometimes, in very rare cases, a new fruit emerges that tastes like a mixture
between both of them.

A big topic of discussion inside the company is "How should the new creations be called?"
A mixture between an apple and a pear could be called an apple-pear, of course, but this doesn't sound very interesting.
The boss finally decides to use the shortest string that contains both names of the original fruits as sub-strings as the new name.
For instance, "applear" contains "apple" and "pear" (APPLEar and apPlEAR), and there is no shorter string that has the same property.
A combination of a cranberry and a boysenberry would therefore be called a "boysecranberry" or a "craboysenberry", for example.

Your job is to write a program that computes such a shortest name for a combination of two given fruits.
Your algorithm should be efficient, otherwise it is unlikely that it will execute in the alloted time for long fruit names.

Input Specification
Each line of the input file contains two strings that represent the names of the fruits that should be combined.
All names have a maximum length of 100 and only consist of alphabetic characters.
Input is terminated by end of file.

Output Specification
For each test case, output the shortest name of the resulting fruit on one line.
If more than one shortest name is possible, any one is acceptable.

Sample Input
apple peach
ananas banana
pear peach

Sample Output
appleach
bananas
pearch

#include <iostream>
#include <algorithm>
using namespace std;

void fun(string s1, string s2) {
	int i,j,m,n;
	m=s1.length();
	n=s2.length();
	int dp[m+1][n+1];
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0){
				dp[i][j]=j;
			}
			else if(j==0){
				dp[i][j]=i;
			}
			else if(s1[i-1]==s2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}else{
				dp[i][j]=1+min(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	/*for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[m][n]<<endl;*/
	i=m;j=n;
	string res="";
	while(i>0 && j>0){
		if(s1[i-1]==s2[j-1]){
			res=s1[i-1]+res;
			i--;j--;
		}else{
			if(dp[i-1][j]<dp[i][j-1]){
				res=s1[i-1]+res;
				i--;
			}else{
				res=s2[j-1]+res;
				j--;
			}
		}
	}
	if(i==0 && j>0){
		res=s2.substr(0, j)+res;
	}else if(i>0 && j==0){
		res=s1.substr(0, i)+res;
	}
	cout<<res<<endl;
}

int main(){
	string s1,s2;
	while(1){
		cin>>s1>>s2;
		if(s1.length()==0){
			break;
		}
		fun(s1,s2);
		s1="";
	}
	return 0;
}

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int i,j,m,n;
	string s1,s2;
	cin>>s1>>s2;
	while(s1!=""){
		int dp[26], dp1[26];
		string res="";
		memset(dp, 0, sizeof(dp));
		memset(dp1, 0, sizeof(dp1));
		m=s1.length();
		n=s2.length();
		for(i=0;i<m;i++){
			dp[s1[i]-'a']++;
		}
		for(i=0;i<n;i++){
			dp1[s2[i]-'a']++;
		}
		for(i=0;i<26;i++){
			j=0;
			while(j<min(dp[i], dp1[i])){
				res+=(i+'a');
				j++;
			}
		}
		cout<<res<<endl;
		s1="";
		cin>>s1>>s2;
	}
	return 0;
}
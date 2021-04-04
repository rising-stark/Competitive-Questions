#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		char c='.';
		size_t f=s.find(c);
		if(f!=string::npos){
			string a=s.substr(f+1);
			int len=a.length();
			reverse(s.begin(), s.end());
			string b=s.substr(s.find(c)+1);
			reverse(b.begin(), b.end());
			int den=(int)(pow(10, len));
			int num=stoi(b)*den+stoi(a);
			int x=__gcd(num, den);
			x=den/x;
			cout<<x<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}
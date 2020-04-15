https://www.geeksforgeeks.org/removing-punctuations-given-string/

Given a string, remove the punctuation from the string if the given character is a punctuation character as classified by the current C locale. The default C locale classifies these characters as punctuation:

!"#$%&'()*+,-./:;?@[\]^_`{|}~ 
Examples:

Input : %welcome' to @geeksforgeek<s
Output : welcome to geeksforgeeks

Input : Hello!!!, he said ---and went.
Output : Hello he said and went

```
// This code runs in O(n) time and O(1) space.
#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin>>s;
	int i,n,k=0,c=0;
	n=s.length();
	cout<<s<<endl;
	for(i=0;i<n;i++){
		if(ispunct(s[i])){
			c++;
		}else {
			if(c>0){
				s[k]=s[i];
			}
			k++;
		}
	}
	cout<<s.substr(0,n-c)<<endl;
	return 0;
}

```

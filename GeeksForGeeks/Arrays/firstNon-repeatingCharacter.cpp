```
/*
https://practice.geeksforgeeks.org/problems/non-repeating-character/0

Given a string S consisting of lowercase Latin Letters. Find the first non repeating character in S.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases.
Each case begins with a single integer N denoting the length of string. The next line contains the string S.

Output:
For each testcase, print the first non repeating character present in string. Print -1 if there is no non repeating character.

Constraints:
1 <= T <= 900
1 <= N <= 104

Example:
Input :
3
5  
hello
12
zxvczbtxyzvy
6
xxyyzz

Output :
h
c
-1
*/

#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
#define INT_MAX 100000000
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int i,n;
        cin>>n;
        string s;
        cin>>s;
        vector<pair<int, int> > freq(26,{0,INT_MAX});
        for(i=0;i<n;i++){
            freq[s[i]-'a'].first++;
            freq[s[i]-'a'].second=i;
        }
        int res=INT_MAX;
        for(i=0;i<26;i++){
            if(freq[i].first==1){
                res=min(res, freq[i].second);
            }
        }
        if(res<INT_MAX){
            cout<<s[res]<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
}
```

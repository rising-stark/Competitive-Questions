/*
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3288/

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

*/

class Solution {
public:
    string getfreq(string a){
        int i;
        string s="";
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for(i=0;i<a.length();i++){
            freq[a[i]-'a']++;
        }
        for(i=0;i<26;i++){
            s+=to_string(freq[i])+",";
        }
        return s;
    }
    
    vector<vector<string> > groupAnagrams(vector<string>& arr) {
        int i,n,j,c=0,flag;
        n=(int)arr.size();
        
        vector<vector<string> > res(n);
        int dp[n];
        unordered_map <string, int> mp;
        
        if(n==0){
            res.resize(0);
            return res;
        }
        for(i=0;i<n;i++){
            string f=getfreq(arr[i]);
            //cout<<f<<endl;
            if(mp.find(f)==mp.end()){
                mp.insert({f,c});
                dp[i]=c;
                c++;
            }else{
                dp[i]=mp[f];
            }
        }
        for(i=0;i<n;i++){
            res[dp[i]].push_back(arr[i]);
            //cout<<dp[i]<<" ";
        }
        res.resize(c);
        return res;
    }
};

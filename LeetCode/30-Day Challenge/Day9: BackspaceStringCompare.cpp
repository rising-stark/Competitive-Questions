```
/*
https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/529/week-2/3291/

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:
1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

class Solution {
public:
    
    string getequal(string s){
        stack<char> st;
        int i,n;
        n=s.length();
        for(i=0;i<n;i++){
            if(s[i]=='#' && st.empty()==false){
                st.pop();
            }else if(s[i]!='#'){
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty()){
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
    
    bool backspaceCompare(string s, string t) {
        s=getequal(s);
        t=getequal(t);
        if(s.compare(t)==0){
            return true;
        }else{
            return false;
        }
    }
};
```

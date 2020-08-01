/*
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3301/

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid.
We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True

Note:
The string size will be in the range [1, 100].
*/
class Solution {
    bool res(string s, int i, int c){
        if(c<0){
            return false;
        }
        if(i==s.length()){
            if(c==0){
                return true;
            }else{
                return false;
            }
        }
        if(s[i]=='('){
            return res(s, i+1, c+1);
        }else if(s[i]==')'){
            return res(s, i+1, c-1);
        }else{
            bool a,b,d;
            a=b=d=false;
            a=res(s, i+1, c+1);
            b=res(s, i+1, c-1);
            d=res(s, i+1, c);
            return (a || b || d);
        }
    }
public:
    bool checkValidString(string s) {
        int i,n;
        stack<int> b,c;
        //return res(s, 0, 0);
        n=s.length();
        for(i=0;i<n;i++){
            if(s[i]=='(')
                b.push(i);
            else if(s[i]=='*'){
                c.push(i);
            }else{
                if(b.empty()){
                    if(c.empty())
                        return false;
                    else {
                        c.pop();
                    }
                }else{
                    b.pop();
                }
            }
            //cout<<"i= "<<i<<"c = "<<c<<" b= "<<b<<endl;
        }
        while(!b.empty() && !c.empty()){
            int x=b.top();
            int y=c.top();
            if(y>x){
                b.pop();
                c.pop();
            }else{
                return false;
            }
        }
        if(b.empty())
            return true;
        return false;
    }
};

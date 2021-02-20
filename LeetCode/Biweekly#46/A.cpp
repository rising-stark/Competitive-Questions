class Solution {
public:
    bool isnice(string x){
        int low[26]={0};
        int up[26]={0};
        for(auto i:x){
            int c=i;
            if(c>=65 && c<=90){
                up[c-65]++;
            }else if(c>=97 && c<=122){
                low[c-97]++;
            }
        }
        for(int i=0;i<26;i++){
            if((low[i]+up[i]) >0){
                if(!(low[i]>=1 && up[i]>=1)){
                    return false;
                }
            }
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        int i, j;
        int n=s.size();
        int ans=0;
        string a="";
        for(i=0;i<n;i++){
            string x="";
            for(j=i;j<n;j++){
                x+=s[j];
                if(isnice(x)){
                    if(x.size()>ans){
                        ans=x.size();
                        a=x;
                    }
                }
            }
        }
        return a;
    }
};
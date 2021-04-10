class Solution {
public:
    #define ll long long int
    ll dp[11][11];
    ll recur(string &arr, int i, int c, int t){
        if(i==0)
            return c;
        ll &ret = dp[i][c];
        if(ret!=-1 && !t)
            return ret;
        int n=(int)arr.size();
        int lmt=t?arr[n-i]-'0':9;
        ll ans=0;
        for(int j=0;j<=lmt;j++){
            ans+=recur(arr, i-1, c+(j==1), t&(j==lmt));
        }
        return t?ans:ret=ans;
    }
    int countDigitOne(int n) {
        memset(dp, -1, sizeof dp);
        string s=to_string(n);
        return recur(s, s.size(), 0, 1);
    }
};
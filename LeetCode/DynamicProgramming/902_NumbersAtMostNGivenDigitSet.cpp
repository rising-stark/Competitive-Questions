class Solution {
    #define ll long long int
    ll dp[10];
    ll recur(string &arr, vector<int>& digits, int i, int t, int lead){
        if(i==0)
            return 1;
        ll &ret = dp[i];
        if(!t && !lead && ret!=-1)
            return ret;
        int n = (int)arr.size();
        int lmt = t?arr[n-i]-'0':9;
        ll ans=0;
        if(lead){
            ans+=recur(arr, digits, i-1, t&(lmt==0), 1);
        }
        for(auto j:digits){
            if(j<=lmt){
                ans+=recur(arr, digits, i-1, t&(j==lmt), 0);
            }
        }
        return (t || lead)?ans:ret=ans;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> d;
        memset(dp, -1, sizeof dp);
        for(auto i:digits){
            d.push_back(i[0]-'0');
        }
        string b=to_string(n);
        return recur(b, d, b.size(), 1, 1)-1;
    }
};
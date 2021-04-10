#define ll long long int
class Solution{   
public:
    ll dp[10];
    ll recur(string &arr, int i, int t, bool flag){
        if(i==0)
            return 1;
        ll &ret = dp[i];
        if(ret!=-1 && !t && !flag)
            return ret;
        int n = (int)arr.size();
        int lmt = t?arr[n-i]-'0':9;
        ll ans=0;
        for(int j=0;j<=5;j++){
            if(flag){
                if(j<=lmt){
                    ans+=recur(arr, i-1, t&(j==lmt), j==0);
                }
            }else{
                if(j!=0 && j<=lmt){
                    ans+=recur(arr, i-1, t&(j==lmt), 0);
                }
            }
        }
        return (t || flag)?ans:ret=ans;
    }
    int countNumbers(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof dp);
        return recur(s, s.size(), 1, 1)-1;
    }
};
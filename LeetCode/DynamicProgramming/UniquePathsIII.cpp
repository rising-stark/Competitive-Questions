https://leetcode.com/problems/unique-paths-iii/submissions/

```
# define MAX 20
class Solution {
public:
    void path(vector<vector<int> > arr, int dp[][MAX], int x, int y, int m, int n, int &res, int c, int i){
        if(x<0 || y<0 || x>=m || y>=n ||  dp[x][y]==1 || arr[x][y]==-1){
            return;
        }
        if(i==c && arr[x][y]==2){
            res++;
            //cout<<res<<endl;
            return;
        }if(arr[x][y]==1 || arr[x][y]==0){
        dp[x][y]=1;
        path(arr, dp, x+1, y, m, n, res, c, i+1);
        path(arr, dp, x-1, y, m, n, res, c, i+1);
        path(arr, dp, x, y+1, m, n, res, c, i+1);
        path(arr, dp, x, y-1, m, n, res, c, i+1);
        dp[x][y]=0;}
    }
    
    int uniquePathsIII(vector<vector<int>>& arr) {
        int i,j,n,m,c=0,res=0,si,sj;
        m=arr.size();
        n=arr[0].size();
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(arr[i][j]==0){
                    c++;
                }
                if(arr[i][j]==1){
                    si=i;
                    sj=j;
                }
            }
        }
        int dp[m][MAX];
        memset(dp, 0, sizeof(dp));
        path(arr, dp, si, sj, m, n, res, c+1, 0);
        return res;
    }
};
```

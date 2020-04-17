

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

```
class Solution {
public:
    bool isSafe(vector<vector<char>>& arr, vector<vector<int>>& dp, int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || dp[i][j]==1 || arr[i][j]=='0'){
            return false;
        }return true;
    }
    void printmat(vector<vector<int>>& dp){
        int i,j,m,n,c=0;
        m=(int)dp.size();
        n=dp[0].size();
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;
    }
    void bfs(vector<vector<char>>& arr, vector<vector<int>>& dp, int i, int j, int m, int n){
        queue<pair<int, int > > q;
        q.push(make_pair(i,j));
        dp[i][j]=1;
        cout<<i<<" "<<j<<endl;
        while(!q.empty()){
            pair<int, int > p=q.front();
            q.pop();
            int x,y;
            x=p.first;
            y=p.second;
            if(isSafe(arr, dp, x+1, y, m, n)){
                dp[x+1][y]=1;
                q.push(make_pair(x+1, y));
            }
            if(isSafe(arr, dp, x-1, y, m, n)){
                dp[x-1][y]=1;
                q.push(make_pair(x-1, y));
            }
            if(isSafe(arr, dp, x, y+1, m, n)){
                dp[x][y+1]=1;
                q.push(make_pair(x, y+1));
            }
            if(isSafe(arr, dp, x, y-1, m, n)){
                dp[x][y-1]=1;
                q.push(make_pair(x, y-1));
            }
        } 
    }
    int numIslands(vector<vector<char>>& arr) {
        int i,j,m,n,c=0;
        if(arr.size()==0){
            return 0;
        }
        m=(int)arr.size();
        n=arr[0].size();
        vector<vector<int> > dp( m , vector<int> (n, 0));
        //printmat(dp);
        //cout<<"m, n, "<<m<<n<<endl;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(dp[i][j]==0 && arr[i][j]=='1'){
                    bfs(arr, dp, i,j,m,n);
                    //printmat(dp);
                    c++;
                }
            }
        }
        return c;
    }
};
```

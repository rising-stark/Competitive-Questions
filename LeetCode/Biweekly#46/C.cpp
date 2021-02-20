class Solution {
public:
    template <typename T1, typename T2, typename T3>struct trio{T1 x; T2 y; T3 z; trio(){};trio(T1 _x, T2 _y, T3 _z):x(_x), y(_y), z(_z){}};
    
    bool issafe(int x, int y, int n, int m){
        if(x<0 || y<0 || x>=n || y>=m)
            return false;
        return true;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& arr) {
        int i, j, n, m;
        n=arr.size();
        m=arr[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<trio<int, int, int> > q;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(arr[i][j]==1){
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            trio t=q.front();
            q.pop();
            for(i=-1;i<2;i++){
                for(j=-1;j<2;j++){
                    int k=abs(i)+abs(j);
                    if(k==0 || k==2)
                        continue;
                    if(issafe(t.x+i, t.y+j, n, m) && vis[t.x+i][t.y+j]==0){
                        vis[t.x+i][t.y+j]=1;
                        q.push({t.x+i, t.y+j, t.z+1});
                        ans[t.x+i][t.y+j]=t.z+1;
                    }
                }
            }
        }
        return ans;
    }
};
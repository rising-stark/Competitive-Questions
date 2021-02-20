#define pii pair<int, int>
class Solution {
    public:
    
    vector<int> adj[100001];
    int cop[51][51];
    int ans[100001];
    vector<int> nums;
    
    void dfs(int u, int p, int d, vector<pii> mp){
        int mx=-1;
        int temp=-1;
        int x=nums[u];
        for(int i=1;i<mp.size();i++){
            if(mp[i].first!=-1 && cop[x][i]==1 && mx<(mp[i].second)){
                mx=mp[i].second;
                temp=mp[i].first;
            }
        }
        ans[u]=temp;
        vector<pii> mp1=mp;
        mp1[x]={u, d};
        for(int v:adj[u]){
            if(v!=p){
                dfs(v, u, d+1, mp1);
            }
        }
    }
    
    vector<int> getCoprimes(vector<int>& nm, vector<vector<int>>& edges) {
        int i, j, n;
        n=nm.size();
        nums=nm;
        memset(cop, 0, sizeof cop);
        for(i=1;i<=50;i++){
            for(j=1;j<=50;j++){
                if(__gcd(i,j)==1)
                    cop[i][j]=1;
            }
        }
        for(i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<pii> mp(51, {-1, -1});
        dfs(0, -1, 0, mp);
        vector<int> k(n);
        for(i=0;i<n;i++){
            k[i]=ans[i];
        }
        return k;
    }
};
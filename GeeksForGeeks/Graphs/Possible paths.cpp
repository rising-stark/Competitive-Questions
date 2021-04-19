class Solution {
public:
    vector<vector<int> > matmult(vector<vector<int> > &a, vector<vector<int> > &b){
        int i, j, k, p, q, r;
        p = (int)a.size();
        q = (int)b.size();
        r = (int)b[0].size();
        vector<vector<int> > res(p, vector<int> (r, 0));
        for(i=0;i<p;i++){
            for(j=0;j<r;j++){
                for(k=0;k<q;k++){
                    res[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        return res;
    }
    

	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    int i, j, n;
	    n = (int)graph.size();
	    vector<vector<int> > res(n, vector<int> (n, 0));
	    vector<vector<int> > a = graph;
	    for(i=0;i<n;i++){
	        res[i][i]=1;
	    }
	    while(k){
	        if(k&1)
	            res=matmult(res, a);
	        a=matmult(a,a);
	        k>>=1;
	    }
	    return res[u][v];
	}

};
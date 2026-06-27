class Solution {
public:
    bool dfs(int i,vector<vector<int>>&adj,vector<int>&col,int col2){
             col[i]=col2;
             for(auto ver:adj[i]){
                if(col[ver]==-1){
                    if(!dfs(ver,adj,col,!col2))
                    return false;
                }
                else if(col[ver]==col2){
                    return false;
                }
             }
             return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto vec:dislikes){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>col(n+1,-1);
        for(int i=1;i<=n;i++){
        if(col[i]==-1){
        if(!dfs(i,adj,col,0))
         return false;
        }
        }
        return true;

    }
};
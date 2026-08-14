class Solution {
public:

 bool dfs(int node,vector<vector<int>>&adj,int dest,vector<int>&visited){
               if(node==dest) return true;
               visited[node]=true;

               for(auto adjc:adj[node]){
                if(!visited[adjc]){
                    if(dfs(adjc,adj,dest,visited)){
                        return true;
                    }
                }
               }
               return false;


 }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>visited(n,0);
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
            if(dfs(source,adj,destination,visited))
            return true;

            return false;

 
     }
};
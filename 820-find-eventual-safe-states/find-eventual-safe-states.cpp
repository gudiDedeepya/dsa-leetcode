class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         int n=graph.size();
        vector<vector<int>> revAdj(n);


for(int i=0;i<n;i++){
    for(auto neigh:graph[i]){
        revAdj[neigh].push_back(i);
    }
}
       
        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++){
            for(int node:revAdj[i])
            indegree[node]++;
        }
        
         queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) 
            {
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:revAdj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);

            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};
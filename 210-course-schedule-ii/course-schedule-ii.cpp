class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

for(auto vec : prerequisites){
    int a = vec[0];
    int b = vec[1];

    adj[b].push_back(a);  // b → a
    indegree[a]++;
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
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);

            }
        }


        vector<int>ans;    

   return topo.size()<numCourses?ans:topo;
    }
};
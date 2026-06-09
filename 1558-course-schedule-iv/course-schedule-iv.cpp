class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);

        for(auto &it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        vector<vector<bool>> reachable(numCourses,
                                       vector<bool>(numCourses, false));

        for(int src = 0; src < numCourses; src++) {

            queue<int> q;
            q.push(src);

            vector<int> vis(numCourses, 0);
            vis[src] = 1;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(auto nxt : adj[node]) {
                    if(!vis[nxt]) {
                        vis[nxt] = 1;
                        reachable[src][nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }

        vector<bool> ans;

        for(auto &q : queries) {
            ans.push_back(reachable[q[0]][q[1]]);
        }

        return ans;
    }
};
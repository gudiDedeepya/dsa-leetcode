class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long mod = 1e9 + 7;

        vector<long long> ways(n, 0);
        ways[0] = 1;

        vector<pair<int,int>> adj[n];

        for(auto vec : roads){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0,0});

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        while(!pq.empty()){

            auto [a,b] = pq.top();
            pq.pop();

            if(a > dist[b]) continue;

            for(auto node : adj[b]){

                long long newDist = a + node.second;

                if(dist[node.first] > newDist){

                    dist[node.first] = newDist;
                    ways[node.first] = ways[b];

                    pq.push({newDist,node.first});
                }

                else if(dist[node.first] == newDist){

                    ways[node.first] =
                        (ways[node.first] + ways[b]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};
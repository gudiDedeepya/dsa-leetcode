class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto vec:flights){
           int u=vec[0];
            int v=vec[1];
           int w= vec[2];
        adj[u].push_back({v, w});
        }

        queue<
        pair<int,pair<int,int>>>pq;

        pq.push({0,{src,0}});
        vector<int>prices(n,INT_MAX);
        prices[src]=0;


        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            int stops=it.first;
            int flight=it.second.first;
            int price=it.second.second;
            //if(flight==dst) return price;
            if(stops==k+1) continue;

            for(auto node:adj[flight]){
                if(prices[node.first]>price+node.second){
                pq.push({stops+1,{node.first,node.second+price}});
                prices[node.first]=price+node.second;
                }

            }
        }

        if(prices[dst]!=INT_MAX) return prices[dst];
        return -1;
    }
};
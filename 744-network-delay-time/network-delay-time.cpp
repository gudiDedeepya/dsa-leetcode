class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];

        for(auto vec:times){
           int u=vec[0];
            int v=vec[1];
           int w= vec[2];
        adj[u].push_back({v, w});
        }
       priority_queue<
      pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;


pq.push({0,k});
//vector<int>visited(n,0);
vector<int>time(n+1,1e9);
time[k]=0;

while(!pq.empty()){
    auto [a,b]=pq.top();
    pq.pop();
    if(a > time[b]) continue;
    for(auto node:adj[b]){
        if(node.second+a<time[node.first]){
            pq.push({node.second+a,node.first});
            time[node.first]=a+node.second;
        }
    }


}

int maxi=*max_element(time.begin()+1,time.end());
if(maxi==1e9) return -1;
return maxi;


    }
};
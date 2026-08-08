class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<pair<int,int>>cost(n);
        for(int i=0;i<n;i++){
            cost[i].first=costs[i][0]-costs[i][1];
            cost[i].second=i;
        }
        sort(cost.begin(),cost.end());
        int ans=0;
        for(int i=0;i<n/2;i++){
            int k=cost[i].second;
            ans+=costs[k][0];
        }
        for(int i=n/2;i<n;i++){
            int k=cost[i].second;
            ans+=costs[k][1];
        }
        return ans;

    }
};
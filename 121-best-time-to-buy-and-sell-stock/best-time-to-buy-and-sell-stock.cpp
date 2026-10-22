class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int max_profit=0;
        int cost=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++){
            profit=prices[i]-cost;
            max_profit=max(profit,max_profit);
            cost=min(cost,prices[i]);
        }
        return max_profit;
    }
};
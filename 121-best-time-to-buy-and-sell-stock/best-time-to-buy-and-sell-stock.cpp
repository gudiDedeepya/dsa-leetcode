class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int cost;
        int min_buy=prices[0];
        for(int i=1;i<prices.size();i++){
            cost=prices[i]-min_buy;
            profit=max(cost,profit);
            min_buy=min(prices[i],min_buy);
        }
        return profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=INT_MIN;
        int min_buy=INT_MAX;

        for(int i=0;i<n;i++){
            min_buy=min(min_buy,prices[i]);
            profit=max(profit,prices[i]-min_buy);
        }

        return profit;
    }
};
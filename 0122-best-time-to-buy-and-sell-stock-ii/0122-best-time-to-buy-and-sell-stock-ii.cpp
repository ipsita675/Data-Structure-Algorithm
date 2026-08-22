class Solution {
public:
    int memo(int i,bool can_buy,vector<int>& prices,vector<vector<int>>& dp){
        if(i==prices.size())return 0;
        if(dp[i][can_buy]!=-1)return dp[i][can_buy];

        int profit=0;
        if(can_buy){
            profit=max(profit,memo(i+1,false,prices,dp)-prices[i]);
            profit=max(profit,memo(i+1,true,prices,dp));
        }
        else{
            profit=max(profit,prices[i]+memo(i+1,true,prices,dp));
            profit=max(profit,memo(i+1,false,prices,dp));
        }

        return dp[i][can_buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return memo(0,true,prices,dp);
    }
};
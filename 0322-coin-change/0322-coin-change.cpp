class Solution {
public:
    int memo(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount==0)return 0;
        if(i==coins.size())return 1e9;
        if(dp[i][amount]!=-1)return dp[i][amount];

        int pick=INT_MAX;
        if(amount>=coins[i])pick=1+memo(i,amount-coins[i],coins,dp);

        int notpick=memo(i+1,amount,coins,dp);

        return dp[i][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=memo(0,amount,coins,dp);
        return (ans>=1e9)? -1:ans;
    }
};
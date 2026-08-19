class Solution {
public:
    int count(int i,int n,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount==0)return 1;
        if(i>=n)return 0;

        if(dp[i][amount]!=-1)return dp[i][amount];

        int pick=0;
        if(amount-coins[i]>=0)pick=count(i,n,amount-coins[i],coins,dp);
        int notpick=count(i+1,n,amount,coins,dp);

        return dp[i][amount]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return count(0,n,amount,coins,dp);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return memo(0,1,fee,dp,n,prices);
    }
    int memo(int i,int buy,int fee,vector<vector<int>>& dp,int n,vector<int>& arr){
        if(i==n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            int pick=-arr[i]+memo(i+1,0,fee,dp,n,arr);
            int notpick=memo(i+1,1,fee,dp,n,arr);
            profit=max(pick,notpick);
        }
        else{
            int pick=arr[i]-fee+memo(i+1,1,fee,dp,n,arr);
            int notpick=memo(i+1,0,fee,dp,n,arr);
            profit=max(pick,notpick);
        }
        return dp[i][buy]=profit;
    }
};
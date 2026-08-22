class Solution {
public:
    int memo(int i,bool can_buy,int ct,vector<int>& prices,vector<vector<vector<int>>>& dp){

        if(i==prices.size() || ct==2)return 0;
        if(dp[i][can_buy][ct]!=-1)return dp[i][can_buy][ct];

        int profit=0;
        if(can_buy){
            int pick=memo(i+1,false,ct,prices,dp)-prices[i];
            int notpick=memo(i+1,true,ct,prices,dp);
            profit=max(pick,notpick);
        }
        else{
            int pick=memo(i+1,true,ct+1,prices,dp)+prices[i];
            int notpick=memo(i+1,false,ct,prices,dp);
            profit=max(pick,notpick);
        }

        return dp[i][can_buy][ct]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return memo(0,true,0,prices,dp);
    }
};
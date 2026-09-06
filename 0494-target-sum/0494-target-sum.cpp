class Solution {
public:
    int memo(int i,int target,vector<vector<int>>& dp,vector<int>& nums){
        int n=nums.size();
        if(i==n)return target==0? 1:0;
        if(dp[i][target]!=-1)return dp[i][target];

        int notpick=memo(i+1,target,dp,nums);
        int pick=0;
        if(target-nums[i]>=0)pick=memo(i+1,target-nums[i],dp,nums);

        return dp[i][target]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum+target<0 || (sum+target)%2!=0)return 0;
        //p+n=sum;
        //p-n=target;
        int positive=(sum+target)/2;
        vector<vector<int>>dp(n,vector<int>(positive+1,-1));
        return memo(0,positive,dp,nums);
    }
};
class Solution {
public:
    bool memo(int i,int k,vector<vector<int>>& dp,vector<int>& nums){
        if(k==0)return true;
        if(i==nums.size())return false;
        if(dp[i][k]!=-1)return dp[i][k];

        bool pick=false;
        if(k>=nums[i])pick=memo(i+1,k-nums[i],dp,nums);
        bool notpick=memo(i+1,k,dp,nums);

        return dp[i][k]=pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2)return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return memo(0,target,dp,nums);
    }
};
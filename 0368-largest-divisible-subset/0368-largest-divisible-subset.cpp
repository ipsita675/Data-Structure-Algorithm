class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1),par(n);

        int len=1;
        int last=0;

        for(int i=0;i<n;i++){
            par[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    par[i]=prev;
                }
            }
            if(dp[i]>len){
                len=dp[i];
                last=i;
            }
        }

        vector<int>ans;
        while(par[last]!=last){
            ans.push_back(nums[last]);
            last=par[last];
        }
        ans.push_back(nums[last]);

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
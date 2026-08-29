class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1),ct(n,1);
        int len=1;

        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[prev]<arr[i]){
                    if(dp[prev]+1>dp[i]){
                        dp[i]=1+dp[prev];
                        ct[i]=ct[prev];
                    }
                    else if(dp[prev]+1==dp[i]){
                        ct[i]+=ct[prev];
                    }
                }
            }
            if(dp[i]>len){
                len=dp[i];
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==len)ans+=ct[i];
        }
        return ans;
    }
};
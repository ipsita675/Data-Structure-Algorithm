class Solution {
public:
    bool memo(int i,int k,int n,vector<int>& stones,unordered_map<int,int>&mp,vector<vector<int>>& dp){
        if(i==n-1)return true;
        if(i<0 || i>=n)return false;
        if(dp[i][k]!=-1)return dp[i][k];

        for(int d=-1;d<=1;d++){
            if(k+d<=0)continue;

            int next=stones[i]+k+d;
            if(mp.count(next)){
                if(memo(mp[next],k+d,n,stones,mp,dp))return dp[i][k]=true;
            }
        } 

        return dp[i][k]=false;
    }
    bool canCross(vector<int>& stones){
        if(stones[1]!=1)return false;
        int n=stones.size();

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[stones[i]]=i;

        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return memo(1,1,n,stones,mp,dp);
    }
};
class Solution {
public:
    int memo(int i,int j,int n,int m,string& text1, string& text2,vector<vector<int>>& dp){
        if(i==n || j==m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        if(text1[i]==text2[j])return dp[i][j]=1+memo(i+1,j+1,n,m,text1,text2,dp);

        int mxlen=0;
        mxlen=max(mxlen,memo(i+1,j,n,m,text1,text2,dp));
        mxlen=max(mxlen,memo(i,j+1,n,m,text1,text2,dp));

        return dp[i][j]=mxlen;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return memo(0,0,n,m,text1,text2,dp);
    }
};
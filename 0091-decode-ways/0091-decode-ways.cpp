class Solution {
public:
    int memo(int i,int n,string s,vector<int>& dp){
        if(i==n)return 1;
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];

        int single=memo(i+1,n,s,dp);
        int doubl=0;
        if(i+1<n){
            int num=(s[i]-'0')*10+(s[i+1]-'0');
            if(num<=26)doubl=memo(i+2,n,s,dp);
        }

        return dp[i]=single+doubl;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return memo(0,n,s,dp);
    }
};
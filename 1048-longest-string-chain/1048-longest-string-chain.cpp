class Solution {
public:
    bool possible(string curr,string prev){
        if(curr.size()!=prev.size()+1)return false;

        int i=0;
        int j=0;

        while(i<curr.size() && j<prev.size()){
            if(curr[i]==prev[j])j++;
            i++;
        }

        return j==prev.size();
    }
    bool static compare(const string& a,const string& b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin(),arr.end(),compare);
        int n=arr.size();
        vector<int>dp(n,1);
        int len=1;

        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(possible(arr[i],arr[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>len){
                len=dp[i];
            }
        }

        return len;
    }
};
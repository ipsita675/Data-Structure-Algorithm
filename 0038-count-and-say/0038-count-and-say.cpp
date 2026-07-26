class Solution {
  public:
    string countAndSay(int n) {
        if(n==1)return "1";
        
        string prev=countAndSay(n-1);
        
        int len=prev.size();
        int ct=1;
        string ans="";

        for(int i=1;i<len;i++){
            if(prev[i]==prev[i-1])ct++;
            else{
                ans.push_back('0'+ct);
                ans.push_back(prev[i-1]);
                ct=1;
            }
        }
        ans.push_back('0'+ct);
        ans.push_back(prev[len-1]);

        return ans;
    }   
};
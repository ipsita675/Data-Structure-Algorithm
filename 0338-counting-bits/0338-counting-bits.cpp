class Solution {
public:
    int hammingWeight(int n) {
        int ct=0;
        while(n){
            ct+=(n&1);
            n=n>>1;
        }
        return ct;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=0;i<=n;i++){
            ans[i]=hammingWeight(i);
        }
        return ans;
    }
};
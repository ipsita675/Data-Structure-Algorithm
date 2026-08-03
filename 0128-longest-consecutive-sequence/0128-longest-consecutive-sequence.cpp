class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s(nums.begin(),nums.end());
        int len=0;

        for(auto it:s){
            if(s.count(it-1)==0){
                int ct=1;
                int x=it;

                while(s.count(x+1)){
                    x++;
                    ct++;
                }

                len=max(len,ct);
            }
        }
        return len;
    }
};
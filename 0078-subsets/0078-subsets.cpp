class Solution {
public:
    void memo(int i,int n,vector<int>& sub,set<vector<int>>& ans,vector<int>& nums){
        if(i==n){
            ans.insert(sub);
            return;
        }

        //pick
        sub.push_back(nums[i]);
        memo(i+1,n,sub,ans,nums);
        sub.pop_back();

        //not pick
        memo(i+1,n,sub,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>ans;
        vector<int>sub;
        memo(0,n,sub,ans,nums);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
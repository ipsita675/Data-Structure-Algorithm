class Solution {
public:
    void choice(vector<int>& nums,int i,set<vector<int>>& ans,vector<int>& sub) {
        if(i==nums.size()) {
            ans.insert(sub);
            return; 
        }

        sub.push_back(nums[i]);
        choice(nums,i+1,ans,sub);
        sub.pop_back();
        choice(nums,i+1,ans,sub);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        vector<int>sub;
        choice(nums,0,ans,sub);
        return vector<vector<int>>(ans.begin(),ans.end()); 
    }
};
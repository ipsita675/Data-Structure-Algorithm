class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int r=n-1;
            int l=i+1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0)ans.insert({nums[i],nums[l],nums[r]});
                if(sum<0)l++;
                else r--;
            }
        }
        vector<vector<int>>res;
        for(auto x:ans){
            res.push_back(x);
        } 
        return res;
    }
};
class Solution {
public:
    void memo(int i,int sum,int target,vector<int>& candidates,vector<vector<int>>& ans,vector<int>& path){
        if(i==candidates.size()){
            if(sum==target){
                ans.push_back(path);
            }
            return;
        }
        
        //pick
        if(sum+candidates[i]<=target){
            path.push_back(candidates[i]);
            memo(i,sum+candidates[i],target,candidates,ans,path);
            path.pop_back();
        }

        //notpick
        memo(i+1,sum,target,candidates,ans,path);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>path;

        memo(0,0,target,candidates,ans,path);
        return ans;
    }
};
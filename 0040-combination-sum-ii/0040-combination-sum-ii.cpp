class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>path;

        memo(0,0,target,candidates,ans,path);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
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
            memo(i+1,sum+candidates[i],target,candidates,ans,path);
            path.pop_back();
        }

        //notpick
        int next_i=i+1;
        while(next_i<candidates.size() && candidates[next_i]==candidates[i])next_i++;
        memo(next_i,sum,target,candidates,ans,path);
    }
};
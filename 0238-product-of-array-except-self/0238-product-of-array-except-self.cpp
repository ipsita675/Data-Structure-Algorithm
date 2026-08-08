class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int zct=0;
        int zi=-1;
        vector<int>ans(n,0);
        int mul=1;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zct++;
                zi=i;
            }
            else mul*=nums[i];
            if(zct>1)return ans;
        }

        if(zi==-1){
            for(int i=0;i<n;i++){
                ans[i]=mul/nums[i];
            }
        }
        else{
            ans[zi]=mul;
        }

        return ans;
    }
};
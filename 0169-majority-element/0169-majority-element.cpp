class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele=nums[0];
        int ct=1;

        for(int i=1;i<n;i++){
            if(nums[i]!=ele){
                ct--;
                if(ct==0){
                    ele=nums[i];
                    ct=1;
                }
            }
            else{
                ct++;
            }
        }

        return ele;
    }
};
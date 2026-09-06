class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele1=INT_MIN;
        int ct1=0;
        int ele2=INT_MAX;
        int ct2=0;

        for(int i=0;i<n;i++){
            if(ct1==0 && nums[i]!=ele2){
                ct1++;
                ele1=nums[i];
            }
            else if(ct2==0 && nums[i]!=ele1){
                ct2++;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)ct1++;
            else if(nums[i]==ele2)ct2++;
            else{
                ct1--;
                ct2--;
            }
        }
        
        ct1=0;
        ct2=0;

        for(int i=0;i<n;i++){
            if(nums[i]==ele1)ct1++;
            else if(nums[i]==ele2)ct2++;
        }
        int maj=n/3+1;

        vector<int>res;
        if(ct1>=maj)res.push_back(ele1);
        if(ct2>=maj && ele1!=ele2)res.push_back(ele2);

        return res;
    }
};
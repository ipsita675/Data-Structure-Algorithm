class Solution {
public:
    void merge(vector<int>& nums,int low,int mid,int high){
        int i=low;
        int j=mid+1;
        vector<int>temp;

        while(i<=mid && j<=high){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i=0;i<temp.size();i++){
            nums[low+i]=temp[i];
        }
    }
    int countpair(vector<int>& nums,int low,int mid,int high){
        int ct=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]>2LL*nums[j])j++;
            ct+=(j-(mid+1));
        }
        return ct;
    }
    int mergesort(vector<int>& nums,int low,int high){
        if(low>=high)return 0;

        int ct=0;
        int mid=low+(high-low)/2;

        ct+=mergesort(nums,low,mid);
        ct+=mergesort(nums,mid+1,high);
        ct+=countpair(nums,low,mid,high);

        merge(nums,low,mid,high);
        return ct;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};
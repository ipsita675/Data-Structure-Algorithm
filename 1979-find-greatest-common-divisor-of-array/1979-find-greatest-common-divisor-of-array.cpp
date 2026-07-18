class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int min_val=*min_element(nums.begin(),nums.end());
        int max_val=*max_element(nums.begin(),nums.end());

        return __gcd(min_val,max_val);
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int pref=0;
        int ct=0;

        for(auto x:nums){
            pref+=x;
            int req=pref-k;

            if(mp.count(req)){
                ct+=mp[req]; 
            }

            mp[pref]++;
        }

        return ct;
    }
};
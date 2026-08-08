class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x:nums)mp[x]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k)pq.pop();
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
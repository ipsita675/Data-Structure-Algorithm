class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }
        return mp.size();
    }
};
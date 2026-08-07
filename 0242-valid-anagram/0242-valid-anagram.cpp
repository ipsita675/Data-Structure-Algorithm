class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        if(n!=t.size())return false;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it:mp){
            if(it.second!=0)return false;
        }
        return true;
    }
};
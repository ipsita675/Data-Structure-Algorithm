class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        unordered_set<char>st;
        int ans=0;

        for(int r=0;r<n;r++){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
        
    
            ans=max(ans,r-l+1);
            st.insert(s[r]);
            
        }

        return ans;
    }
};
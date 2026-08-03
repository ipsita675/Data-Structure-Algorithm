class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        int mxfreq=0;
        int mxlen=0;
        int hash[26]={0};

        while(r<n){
            hash[s[r]-'A']++;
            mxfreq=max(mxfreq,hash[s[r]-'A']);

            if(r-l+1-mxfreq>k){
                hash[s[l]-'A']--;
                l++;
            }

            mxlen=max(mxlen,r-l+1);
            r++;
        }
        return mxlen;
    }
};
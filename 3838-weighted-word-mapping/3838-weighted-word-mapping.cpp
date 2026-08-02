class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto w:words){
            int score=0;
            for(auto c:w)score+=weights[c-'a'];
            score%=26;
            ans+=('z'-score);
        }
        return ans;
    }
};
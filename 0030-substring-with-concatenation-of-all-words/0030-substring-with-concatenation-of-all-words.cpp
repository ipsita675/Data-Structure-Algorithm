class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mpp;
        vector<int>res;
        int len=words[0].size();

        for(auto w:words)mpp[w]++;

        for(int offset=0;offset<len;++offset){
            int size=0;
            unordered_map<string,int>seen;
            for(int i=offset;i+len<=s.size();i+=len){
                string sub=s.substr(i,len);
                if(!mpp.count(sub)){
                    seen.clear();
                    size=0;
                    continue;
                }

                seen[sub]++;
                size++;

                while(seen[sub]>mpp[sub]){
                    string first=s.substr(i-(size-1)*len,len);
                    seen[first]--;
                    size--;
                }
                
                if(size==words.size())res.push_back(i-(size-1)*len);
            }
        }

        return res;
    }
};
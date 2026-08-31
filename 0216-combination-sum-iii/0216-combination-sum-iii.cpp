class Solution {
public:
    void subs(int i,int k,vector<int>& s, set<vector<int>>& res,int n){
        if(s.size()==n && k==0){
            res.insert(s);
            return;
        }

        for(int j=i;j<10;j++){
            s.push_back(j);
            if(k-j>=0)subs(j+1,k-j,s,res,n);
            s.pop_back();
        }
    }  	
    vector<vector<int>> combinationSum3(int k, int n) {
       
        set<vector<int>>res;
        vector<int>s;
        subs(1,n,s,res,k);
        
        return vector<vector<int>>(res.begin(),res.end());
        
    }
};
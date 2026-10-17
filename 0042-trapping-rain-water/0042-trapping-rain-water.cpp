class Solution {
public:
    vector<int>right_max(vector<int>& h){
        int n=h.size();
        vector<int>ans(n);
        int maxi=0;

        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,h[i]);
            ans[i]=maxi;
        }

        return ans;
    }
    vector<int>left_max(vector<int>& h){
        int n=h.size();
        vector<int>ans(n);
        int maxi=0;

        for(int i=0;i<n;i++){
            maxi=max(maxi,h[i]);
            ans[i]=maxi;
        }

        return ans;
    }
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int>right=right_max(h);
        vector<int>left=left_max(h);

        int water=0;
        for(int i=1;i<n-1;i++){
            water+=(min(right[i],left[i])-h[i]);
        }

        return water;
    }
};
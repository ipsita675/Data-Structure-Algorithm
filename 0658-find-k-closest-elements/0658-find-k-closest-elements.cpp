class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();

        vector<pair<int,int>>dist;
        for(int i=0;i<n;i++){
            int d=abs(arr[i]-x);
            dist.push_back({d,arr[i]});
        }
        sort(dist.begin(),dist.end());

        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(dist[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
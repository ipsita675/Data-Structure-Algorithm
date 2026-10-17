class Solution {
public:
    bool possible(vector<int>& piles,int k, int h){
        long long hours=0;
        for(int p:piles){
            hours+=((p+k-1)/k);
        }

        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(possible(piles,mid,h)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }
};
class Solution {
public:
    bool possible(int k,int days,vector<int>& weights){
        int n=weights.size();
        int sum=0;
        int d=1;
        for(int i=0;i<n;i++){
            if(sum+weights[i]>k){
                sum=0;
                d++;
            }
            sum+=weights[i];
        }

        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid=low+(high-low)/2;

            if(possible(mid,days,weights)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};
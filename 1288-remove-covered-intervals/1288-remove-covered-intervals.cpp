class Solution {
public:
    bool static compare(const vector<int>& a,const vector<int>& b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),compare);

        int ct=0;
        int end=intervals[0][1];

        for(int i=1;i<n;i++){
            int curr_end=intervals[i][1];
            if(curr_end<=end)ct++;
            else end=curr_end;
        }

        return n-ct;
    }
};
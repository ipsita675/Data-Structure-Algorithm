class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();

        int tank=0;
        int start=0;

        int tot_cost=accumulate(cost.begin(),cost.end(),0);
        int tot_gas=accumulate(gas.begin(),gas.end(),0);

        if(tot_cost>tot_gas)return -1;


        for(int i=0;i<n;i++){
            int diff=gas[i]-cost[i];
            tank+=diff;
            if(tank<0){
                start=i+1;
                tank=0;
            }
        }

        return start;
    }
};
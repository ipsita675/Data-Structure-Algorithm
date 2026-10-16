class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++)pq.push(stones[i]);

        while(pq.size()>=2){
            int w1=pq.top();
            pq.pop();
            int w2=pq.top();
            pq.pop();

            if(w1!=w2)pq.push(w1-w2);
        }

        if(pq.empty())return 0;
        return pq.top();
    }
};
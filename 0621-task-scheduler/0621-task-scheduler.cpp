class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>>pq;
        unordered_map<char,int>mp;

        for(auto t:tasks){
            mp[t]++;
        }

        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        int time=0;
        queue<pair<int,pair<int,int>>>q;

        while(!pq.empty() || !q.empty()){
            time++;

            if(!pq.empty()){
                auto [freq,task]=pq.top();
                pq.pop();

                freq--;
                if(freq!=0)q.push({time+n,{freq,task}});
            }

            if(q.front().first==time){
                pq.push(q.front().second);
                q.pop();
            }
        }

        return time;
    }
};
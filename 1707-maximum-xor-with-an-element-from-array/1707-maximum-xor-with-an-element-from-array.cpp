struct Node{
    Node* links[2];

    Node(){
        links[0]=nullptr;
        links[1]=nullptr;
    }
};
class Solution {
private:
    Node* root;

    void insert(int num){
        Node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;

            if(!curr->links[bit])curr->links[bit]=new Node();
            curr=curr->links[bit];
        }
    }

    int findMaxXOR(int x){
        Node* curr=root;
        int maxXOR=0;

        for(int i=31;i>=0;i--){
            int bit=(x>>i)&1;
            int oppo=1-bit;

            if(curr->links[oppo]){
                maxXOR|=(1<<i);
                curr=curr->links[oppo];
            } 
            else curr=curr->links[bit];
        }
        return maxXOR;
    }

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries){
        int qSize=queries.size();
        vector<int>ans(qSize,-1);

        //{m, x, originalIndex}
        vector<vector<int>>offlineQueries(qSize);
        for(int i=0;i<qSize;i++){
            offlineQueries[i]={queries[i][1],queries[i][0],i};
        }

        sort(nums.begin(),nums.end());
        sort(offlineQueries.begin(),offlineQueries.end());

        root=new Node();
        int numIdx=0;
        int totalNums=nums.size();

        for(const auto& q:offlineQueries){
            int m=q[0];
            int x=q[1];
            int queryIdx=q[2];

            while(numIdx<totalNums && nums[numIdx]<=m){
                insert(nums[numIdx]);
                numIdx++;
            }

            if(numIdx>0)ans[queryIdx]=findMaxXOR(x);
        }
        return ans;
    }
};


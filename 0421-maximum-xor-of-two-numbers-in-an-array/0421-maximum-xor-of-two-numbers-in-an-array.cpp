struct Node{
    Node* links[2];
    Node() {
        links[0]=nullptr;
        links[1]=nullptr;
    }
};
class Solution {
    Node* root;
public:
    void insert(int num){
        Node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!curr->links[bit])curr->links[bit]=new Node();
            curr=curr->links[bit];
        }
    }
    int maxXOR(int num){
        Node* curr=root;
        int x=0;

        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            int oppo=1-bit;

            if(curr->links[oppo]){
                x|=(1<<i); //onning the ith bit
                curr=curr->links[oppo];
            }
            else curr=curr->links[bit];
        }

        return x;
    }
	public:
		int findMaximumXOR(vector<int>& nums) {
		    root=new Node();
            for(auto num:nums)insert(num);

            int ans=0;
            for(auto num:nums)ans=max(ans,maxXOR(num));
            return ans;
    	}
};
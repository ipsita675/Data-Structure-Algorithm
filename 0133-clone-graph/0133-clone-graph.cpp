/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        
        unordered_map<Node*,Node*>mp;
        mp[node]=new Node(node->val);

        queue<Node*>q;
        q.push(node);

        while(!q.empty()){
            Node* curr=q.front();
            q.pop();

            for(auto nxt:curr->neighbors){
                if(!mp.count(nxt)){
                    mp[nxt]=new Node(nxt->val);
                    q.push(nxt);
                }
                mp[curr]->neighbors.push_back(mp[nxt]);
            }
        }

        return mp[node];
    }
};
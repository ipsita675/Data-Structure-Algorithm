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
        unordered_map<Node*,Node*>clone;

        queue<Node*>q;
        q.push(node);
        clone[node]=new Node(node->val);

        while(!q.empty()){
            Node* curr=q.front();
            q.pop();

            for(auto nxt:curr->neighbors){
                if(!clone.count(nxt)){
                    clone[nxt]=new Node(nxt->val);
                    q.push(nxt);
                }
                clone[curr]->neighbors.push_back(clone[nxt]);
            }
        }
        return clone[node];
    }
};
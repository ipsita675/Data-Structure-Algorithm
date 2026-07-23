struct Node{
    Node* children[26];
    bool isEnd;
    Node(){
        isEnd=false;
        for(int i=0;i<26;i++)children[i]=nullptr;
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word) {
        Node* curr=root;

        for(auto c:word){
            int i=c-'a';
            if(!curr->children[i])curr->children[i]=new Node();
            curr=curr->children[i];
        } 

        curr->isEnd=true;
    }
    bool search(string word) {
        Node* curr=root;

        for(auto c:word){
            int i=c-'a';
            if(!curr->children[i])return false;
            curr=curr->children[i];
        } 

        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        Node* curr=root;

        for(auto c:prefix){
            int i=c-'a';
            if(!curr->children[i])return false;
            curr=curr->children[i];
        } 

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
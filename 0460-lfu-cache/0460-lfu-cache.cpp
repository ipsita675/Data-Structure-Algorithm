struct Node {
    int key;
    int value;
    int cnt;        // Holds the access frequency of this specific node 
    Node* next;     
    Node* prev;     

    Node(int _key,int _value){
        key=_key;
        value=_value;
        cnt=1;     
        next=nullptr;
        prev=nullptr;
    }
};

// A list that holds ALL nodes sharing the SAME frequency count.
// Nodes are arranged in Least Recently Used (LRU) order:
// - Head (dummy): Most Recently Used (MRU) node sits right after head.
// - Tail (dummy): Least Recently Used (LRU) node sits right before tail.
struct List {
    int size;       // Number of active data nodes in this frequency list
    Node* head;    
    Node* tail;     

    List(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail; 
        tail->prev=head;
        size=0;
    }

    void addFront(Node* node) {
        Node* temp=head->next;
        
        node->next=temp;
        node->prev=head;

        head->next=node;
        temp->prev=node;
        
        size++;
    }

    void removeNode(Node* delnode) {
        Node* prevNode=delnode->prev;
        Node* nextNode=delnode->next;
        
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        
        size--;
    }
};

class LFUCache {
private:
    
    unordered_map<int,Node*>keyNode;       // Map: key -> direct pointer to Node
    unordered_map<int,List*>freqListMap;  // Map: frequency -> pointer to List of nodes with that frequency

    int capacity;  // Maximum capacity of the cache
    int minFreq;   // Tracks the MINIMUM frequency currently present in the cache
    int curSize;   // Tracks current total number of elements in the cache

    
    // Called whenever a node's frequency increases (via get() or updating put()).
    // Moves node from list `oldFreq` -> list `oldFreq + 1`.
    void updateFreqListMap(Node* node) {
        int oldFreq=node->cnt;

        // Step A: Remove the node from its current frequency list
        freqListMap[oldFreq]->removeNode(node);//listHead*->remove

        // Step B: If this node was in the minFreq list AND that list is now empty,So the global minimum frequency must increment by 1!
        if(oldFreq==minFreq && freqListMap[oldFreq]->size==0)minFreq++;

        // Step C: Increment the node's frequency counter
        node->cnt++;

        // Step D: If a list for this new frequency doesn't exist yet, create it
        if(freqListMap.find(node->cnt)==freqListMap.end()){
            freqListMap[node->cnt]=new List();
        }

        // Step E: Insert node at the front of its new higher-frequency list
        freqListMap[node->cnt]->addFront(node);
    }

public:
    LFUCache(int cap) {
        capacity=cap;
        minFreq=0;
        curSize=0;
    }

    int get(int key) {
        if(keyNode.find(key)==keyNode.end())return -1;

        Node* node=keyNode[key];
        int val=node->value;

        updateFreqListMap(node);

        return val;
    }
    
    void put(int key, int value) {
        if(capacity==0)return;

        // CASE 1: KEY ALREADY EXISTS
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->value=value;      
            updateFreqListMap(node);  
            return;
        }

        // CASE 2: CACHE IS FULL -> EVICTION NEEDED
        if(curSize==capacity) {
            // Find the list with to the smallest frequency currently in cache
            List* lfuList=freqListMap[minFreq];

            // In LFU, if there's a tie in frequency, evict the LEAST RECENTLY USED, right before dummy tail (`lfuList->tail->prev`).
            Node* nodeToEvict=lfuList->tail->prev;

            // Remove node from hashmap & frequency list
            keyNode.erase(nodeToEvict->key);
            lfuList->removeNode(nodeToEvict);

            // Free heap memory to prevent memory leaks
            delete nodeToEvict;

            curSize--;
        }

        //INSERT NEW KEY
        curSize++;
        minFreq=1; // A brand new node ALWAYS starts with frequency = 1!

        // Ensure list for frequency 1 exists
        if(freqListMap.find(minFreq)==freqListMap.end()){
            freqListMap[minFreq]=new List();
        }

        // Create new node and attach it to both the frequency list and lookup map
        Node* newNode=new Node(key, value);
        freqListMap[minFreq]->addFront(newNode);
        keyNode[key]=newNode;
    }
};
struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};
class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> dic;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        //if the key doesn't exist then delete
        if(dic.find(key) == dic.end()){
            return -1;
        }

        //otherwise the key exists
        Node* node = dic[key];
        remove(node);
        add(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(dic.find(key) != dic.end()){
            Node* oldNode = dic[key];
            remove(oldNode);
        }

        Node* node = new Node(key, value);
        dic[key] = node;
        add(node);

        if(dic.size() > capacity){
            Node* nodeToDelete = head->next;
            remove(nodeToDelete);
            dic.erase(nodeToDelete->key);
        }
    }

    void add(Node* node){
        Node* prevNode = tail->prev;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = tail;
        tail->prev = node;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/*
    Input
    ["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
                            [[3], [1], [2], [3], [4], [], [], [], [4], []]
    Output
                        [null, true, true, true, false, 3, true, true, true, 4]
*/

struct Node {
    int val;
    Node* next;
    Node(){}
    Node(int x){
        val = x;
        next = NULL;
    }
};
class MyCircularQueue {
public:
    Node* Q;
    Node* front; 
    Node* rear;
    int maxSize, curSize;
    MyCircularQueue(int k) {
        curSize = 0;
        maxSize = k;
        front = rear = Q = new Node(-1);
    }
    
    bool enQueue(int value) {
        if(curSize == maxSize) return false;
        if(curSize + 1 <= maxSize){
            Node* temp = new Node(value);
            rear -> next = temp;
            rear = rear -> next;
            if(curSize == 0) front = front->next;
            curSize++;
        }
        return true;;
    }
    
    bool deQueue() {
        if(curSize == 0) return false;
        curSize--;
        //this will reaturn -1 when the queue is empty
        if(curSize == 0) front = rear = Q;
        else front = front->next;
        return true;
    }
    
    int Front() {
        return front->val;
    }
    
    int Rear() {
        return rear->val;
    }
    
    bool isEmpty() {
        if(curSize == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(curSize == maxSize) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
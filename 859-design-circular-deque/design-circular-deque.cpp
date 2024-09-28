class MyCircularDeque {
public:

deque<int>dq;
int k;
    MyCircularDeque(int K){
        k=K;
    }
    
    bool insertFront(int value) {
        if(dq.size()+1<=k){
            dq.push_front(value);
            return 1;
        }
        return 0;
    }
    
    bool insertLast(int value) {
        if(dq.size()+1<=k){
            dq.push_back(value);
            return 1;
        }
        return 0;
    }
    
    bool deleteFront() {
        if(!dq.empty()){
            dq.pop_front();
            return 1;
        }
        return 0;
    }
    
    bool deleteLast() {
        if(!dq.empty()){
            dq.pop_back();
            return 1;
        }
        return 0; 
    }
    
    int getFront() {
        if(dq.empty()){
            return -1;
        }
        return dq.front();
    }
    
    int getRear() {
        if(dq.empty()){
            return -1;
        }
        return dq.back();
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return dq.size()==k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
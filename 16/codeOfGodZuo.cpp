class MyCircularDeque {
private:
    vector<int> dequeue;
    int l, r, size, capacity;
public:
    MyCircularDeque(int k) {
        dequeue = vector<int>(k);
        l = r = size = 0;
        capacity = k;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            r = l = 0;
            dequeue[l] = value;
        }
        else{
            l = l==0 ? capacity-1 : l-1;
            dequeue[l] = value;
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            r = l = 0;
            dequeue[r] = value;
        }
        else{
            r = r==capacity-1 ? 0 : r+1;
            dequeue[r] = value;
        }
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        l = l==capacity-1 ? 0 : l+1;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        r = r==0 ? capacity-1 : r-1;
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return dequeue[l];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return dequeue[r];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
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
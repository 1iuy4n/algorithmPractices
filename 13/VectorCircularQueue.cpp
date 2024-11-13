class MyCircularQueue {
private:
    int l;
    int r;
    int size;
    int capacity;
    vector<int> elements;
public:
    MyCircularQueue(int k) {
        l = r = 0;
        size = 0;
        capacity = k;
        elements = vector<int>(capacity);
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        elements[r] = value;
        r = r==capacity-1 ? 0 : r+1;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        l = l==capacity-1 ? 0 : l+1;
        --size;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return elements[l];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        int tail = r==0 ? capacity-1 : r-1;
        return elements[tail];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
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
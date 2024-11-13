class MyStack {
private:
    queue<int> q1;
    int size = 0;
public:
    MyStack() {
    }
    
    void push(int x) {
        if(q1.empty()){
            q1.push(x);
        }
        else{
            q1.push(x);
            for(int i=0;i<size;i++){
                q1.push(q1.front());
                q1.pop();
            }
        }
        size++;
        cout << q1.front()<<endl;
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        size--;
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
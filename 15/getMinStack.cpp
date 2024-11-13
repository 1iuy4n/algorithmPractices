class MinStack {
private:
    stack<int> minstack;
    stack<int> dataStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        dataStack.push(val);
        if(minstack.empty()){
            minstack.push(val);
        }
        else{
            if(val<minstack.top()) minstack.push(val);
            else minstack.push(minstack.top());
        }
    }
    
    void pop() {
        dataStack.pop();
        minstack.pop();
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
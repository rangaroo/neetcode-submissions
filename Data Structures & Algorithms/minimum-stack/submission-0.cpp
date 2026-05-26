class MinStack {
public:
    stack<int> s;
    stack<int> mins;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (mins.empty()) {
            mins.push(val);
        } else {
            mins.push(min(mins.top(), val));
        }
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    // When new item is added,
    // maybe i need to keep track of elements by order?
    int getMin() {
        return mins.top();
    }
};

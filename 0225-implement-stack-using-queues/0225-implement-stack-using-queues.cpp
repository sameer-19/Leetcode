class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty())
        {
            q1.push(x);
            return;
        }
        
        int sz = q1.size(), i = 0;
        q1.push(x);
        while(i<sz)
        {
            int top = q1.front();
            q1.pop();
            q1.push(top);
            i++;
        }
    }
    
    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
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
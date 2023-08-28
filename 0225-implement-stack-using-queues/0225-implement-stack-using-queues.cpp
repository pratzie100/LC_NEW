class MyStack {
public:
    deque<int>dq;
    MyStack() {
        
    }
    
    void push(int x) {
        dq.push_back(x);
    }
    
    int pop() {
        int x=dq.back();
        dq.pop_back();
        return x;
    }
    
    int top() {
        return dq.back();
    }
    
    bool empty() {
        return dq.empty();
    }
};
// public:
//     stack<int>s;
//     MyStack() {
        
//     }
    
//     void push(int x) {
//         s.push(x);
//     }
    
//     int pop() {
//         int x=s.top();
//         s.pop();
//         return x;
//     }
    
//     int top() {
//         return s.top();
//     }
    
//     bool empty() {
//         return s.empty();
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
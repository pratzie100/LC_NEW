class MyStack {
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() {

    }
    
    void push(int x) {
        // q2.push(x);
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // swap(q1,q2);


       // q1.push(x);


        int s=q1.size();
        q1.push(x);
        for(int i=0;i<s;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        // if(q1.empty()) return -1;
        // int y=q1.front();
        // q1.pop();
        // return y;



        // if(q1.empty()) return -1;
        // while(q1.size()>1) {
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // int y=q1.front();
        // q1.pop();
        // swap(q1,q2);
        // return y;


        if(q1.empty()) return -1;
        int y=q1.front();
        q1.pop();
        return y;
    }
    
    int top() {

        // return q1.empty()? -1:q1.front();
        

        // if(q1.empty()) return -1;
        // while(q1.size()>1) {
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // int y=q1.front();
        // q1.pop();
        // q2.push(y); // reinsert it to maintain the stack
        // swap(q2,q1);
        // return y;



        return q1.empty()? -1:q1.front();
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
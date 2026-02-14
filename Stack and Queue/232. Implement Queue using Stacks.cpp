// https://leetcode.com/problems/implement-queue-using-stacks/description/
class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int a= st2.top();
        st2.pop();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return a;
    }
    
    int peek() {
        while(st1.size()>1)
        {
            st2.push(st1.top());
            st1.pop();
        }
        int a= st1.top();
        
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return a;
    }
    
    bool empty() {
        return st1.size()==0?true:false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
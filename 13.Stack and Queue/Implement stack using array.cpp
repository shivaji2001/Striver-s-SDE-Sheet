// https://www.geeksforgeeks.org/problems/implement-stack-using-array/1
class myStack {
  public:
    int bottom;
    int top;
    int size;
    vector<int>st;
    myStack(int n) {
        
        bottom=-1;
        top=-1;
        size=n;
        st=vector<int>(n,-1);
    }

    bool isEmpty() {
        return top==-1;
    }

    bool isFull() {
       return top==size-1;
    }

    void push(int x) {
        top++;
        
        st[top]=x;
        
    }

    void pop() {
        if(top!=-1)
         top--;
    }

    int peek() {
        if(top==-1) return -1;
        return st[top];
    }
};
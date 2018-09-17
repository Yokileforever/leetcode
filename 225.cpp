class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        size = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Q.push(x);
        for (int i = 0; i < size; ++i) {
            int tmp = Q.front();
            Q.pop();
            Q.push(tmp);
        }
        size++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        size--;
        int x = Q.front();
        Q.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return Q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return size == 0;
    }
private:
    queue<int> Q;
    int size;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
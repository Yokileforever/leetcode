class MinStack {
    private List<Integer> list;
    private List<Integer> minStack;
    /** initialize your data structure here. */
    public MinStack() {
        list = new ArrayList<Integer>();
        minStack = new ArrayList<Integer>();
    }
    
    public void push(int x) {
        list.add(x);
        if (minStack.isEmpty()) {
            minStack.add(x);
        } else {
            if (x <= getMin()) {
                minStack.add(x);
            }
        }
    }
    
    public void pop() {
        int x = top();
        list.remove(list.size() - 1);
        if (x == getMin()) {
            minStack.remove(minStack.size() - 1);
        }
    }
    
    public int top() {
        return list.get(list.size() - 1);
    }
    
    public int getMin() {
        return minStack.get(minStack.size() - 1);
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


class MinStack {
    private Stack<Integer> list;
    private Stack<Integer> minStack;
    /** initialize your data structure here. */
    public MinStack() {
        list = new Stack<Integer>();
        minStack = new Stack<Integer>();
    }
    
    public void push(int x) {
        list.push(x);
        if (minStack.isEmpty()) {
            minStack.push(x);
        } else {
            if (x <= getMin()) {
                minStack.push(x);
            }
        }
    }
    
    public void pop() {
        int x = top();
        list.pop();
        if (x == getMin()) {
            minStack.pop();
        }
    }
    
    public int top() {
        return list.peek();
    }
    
    public int getMin() {
        return minStack.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
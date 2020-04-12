```
/*
https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/529/week-2/3292/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

class MinStack {
public:
    /** initialize your data structure here. */
    
        stack<pair<int, int> > s;
    MinStack() {
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(make_pair(x,x));
        }
        else{
            int y=s.top().second;
            s.push(make_pair(x,min(x,y)));
        }
    }
    
    void pop() {
        if(!s.empty()){
            s.pop();
        }
    }
    
    int top() {
        if(!s.empty()){
            return s.top().first;
        }
        return -1;
    }
    
    int getMin() {
        if(!s.empty()){
            return s.top().second;
        }
        return INT_MIN;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

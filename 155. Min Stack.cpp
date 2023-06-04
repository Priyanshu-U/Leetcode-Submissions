# Using 2 STL Stacks

class MinStack {
public:
    stack<int> store;
    stack<int> min;
    MinStack() {
        this->min.push(INT_MAX);
    }
    
    void push(int val) {
        if(val<=this->min.top()){
            this->min.push(val);
            this->store.push(val);
        }
        else{
            this->store.push(val);
        }
    }
    
    void pop() {
        if(this->store.top() == this->min.top())
        {
            this->store.pop();
            this->min.pop();
        }
        else{
            this->store.pop();
        }
    }
    
    int top() {
        return this->store.top();
    }
    
    int getMin() {
        return this->min.top();
    }
};

/*
class MinStack {
public:
    MinStack() {

    }
    
    void push(int x) {
        st1.push(x);
        if(!st2.empty())
        {
            if(st2.top()<x) st2.push(st2.top());
            else st2.push(x);
        }
        else
        {
            st2.push(x);
        }
    }
    
    void pop() {
        if(st1.empty()) return;
        st1.pop();
        st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }

private:
    stack<int> st1;
    stack<int> st2;
};
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
	if(st1.empty()) {
	    min = x+1;
	}
	st1.push(x-min);
	if(x<min) {
	    min = x;
	}
    }
    
    void pop() {
        if(st1.empty()) return;
	if(st1.top()<0) {
	    min -= st1.top();
	}
        st1.pop();
    }
    
    int top() {
	int top = st1.top();
	if(top<0) {
	    return min;
	}
	else {
	    return min+top;
	}
    }
    
    int getMin() {
        return min;
    }

private:
    stack<int> st1;
    int min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

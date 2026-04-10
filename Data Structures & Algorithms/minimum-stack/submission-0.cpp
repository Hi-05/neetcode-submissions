class MinStack {
public:

    stack<int> st;
    stack<int> mn;
    MinStack() {
        
        // st.clear();
        // mn.clear();
    }
    
    void push(int val) {
        
        st.push(val);

        if(!mn.empty() && val <= mn.top()){
            mn.push(val);
        }
        else if(mn.empty()){
            mn.push(val);
        }


    }
    
    void pop() {

        int val = st.top();
        st.pop();

        if(!mn.empty() && mn.top() == val) mn.pop();
        
    }
    
    int top() {
        
        return st.top();
    }
    
    int getMin() {
        
        return mn.top();
    }
};

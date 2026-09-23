class MinStack {
public:
    long long minEle;
    stack<long long>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minEle = val;
        }
        else {
            if(val >= minEle){
                st.push(val);
            } else if(val < minEle){
                st.push(2LL *val - minEle);
                minEle = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        if(st.top() >= minEle){
            st.pop();
        } else if(st.top() < minEle){
            minEle = 2LL *minEle - st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        if(st.top() >= minEle){
            return st.top();
        } else {
            return minEle;
        }
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
        return minEle;
    }
};

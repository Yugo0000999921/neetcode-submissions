class MinStack {
private:
    std::stack<int> st;
    std::stack<int> minSt;

public:

    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        // 2. st.top() と関数として呼び出す。空チェックも入れておくと安全
        if (!st.empty() && !minSt.empty() && st.top() == minSt.top()) {
            minSt.pop();
        }
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
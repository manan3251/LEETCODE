class MinStack {
    stack<long long> st;  // use long long to prevent overflow
    long long minVal;

public:
    MinStack() {}

    void push(int val) {
        long long value = val;
        if (st.empty()) {
            minVal = value;
            st.push(value);
        } else {
            if (value >= minVal) {
                st.push(value);
            } else {
                // encode smaller value
                st.push(2 * value - minVal);
                minVal = value;
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long topVal = st.top();
        st.pop();
        if (topVal < minVal) {
            // decode previous min
            minVal = 2 * minVal - topVal;
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long topVal = st.top();
        if (topVal >= minVal) return (int)topVal;
        return (int)minVal;
    }

    int getMin() {
        return (int)minVal;
    }
};
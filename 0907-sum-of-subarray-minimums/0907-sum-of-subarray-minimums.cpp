class Solution {
public:
    static const int MOD = 1e9 + 7;

    // Previous Smaller Element distance
    vector<int> PSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty())
                pse[i] = i + 1;
            else
                pse[i] = i - st.top();

            st.push(i);
        }
        return pse;
    }

    // Next Smaller or Equal Element distance
    vector<int> NSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                nse[i] = n - i;
            else
                nse[i] = st.top() - i;

            st.push(i);
        }
        return nse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> left = PSE(arr);
        vector<int> right = NSE(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long contribution =
                (1LL * arr[i] * left[i] * right[i]) % MOD;
            total = (total + contribution) % MOD;
        }

        return total;
    }
};

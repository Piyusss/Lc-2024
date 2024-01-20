class Solution {
public:
    const int m = 1000000007;
    int sumSubarrayMins(vector<int>& a) {
        stack<int> st;
        long s = 0;
        for (int i = 0; i <= a.size(); i++) {
            while (!st.empty() && (i == a.size() 
            || a[st.top()] >= a[i])) {
                int mid = st.top();
                st.pop();
                int l = st.empty() ? -1 : st.top();
                int r = i;
                long count = (mid - l) * (r - mid) % m;
                s += (count * a[mid]) % m;
                s %= m;
            }
            st.push(i);
        }
        return static_cast<int>(s);
    }
};
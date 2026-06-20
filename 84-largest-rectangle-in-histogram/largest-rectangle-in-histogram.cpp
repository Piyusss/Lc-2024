class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        stack<int>st;
        int maxi=0;

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int ht=heights[st.top()];
                st.pop();

                int pse=st.empty()?-1:st.top();
                int nse=i;

                maxi=max(maxi,ht*(nse-pse-1));
            }
            st.push(i);
        }

        return maxi;
    }
};
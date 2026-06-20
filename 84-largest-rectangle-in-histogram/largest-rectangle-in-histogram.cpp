class Solution {
public:

    vector<int>nse,pse;

    void preCalcPse(vector<int>&heights,int n){
        pse.resize(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
    }

    void preCalcNse(vector<int>&heights,int n){

        nse.resize(n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        int maxi=0;

        preCalcPse(heights,n);
        preCalcNse(heights,n);

        for(int i=0;i<n;i++){
            int area=heights[i]*(nse[i]-pse[i]-1);
            maxi=max(maxi,area);
        }

        return maxi;
    }
};
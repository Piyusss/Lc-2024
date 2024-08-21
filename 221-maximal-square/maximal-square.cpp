class Solution {
public:
    int largestSquareArea(vector<int>& nums) {
        int n=nums.size();

        vector<int>ls(n),rs(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i])st.pop();
            if(st.empty())ls[i]=0;
            else ls[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i])st.pop();
            if(st.empty())rs[i]=n-1;
            else rs[i]=st.top()-1;
            st.push(i);
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            int a=nums[i];
            int b=1+rs[i]-ls[i];
            int mini=min(a,b);
            maxi=max(maxi,(mini*mini));
        }
        return maxi;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int maxi=0;
        vector<int>histo(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')histo[j]++;
                else histo[j]=0;
            }
            int area=largestSquareArea(histo);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
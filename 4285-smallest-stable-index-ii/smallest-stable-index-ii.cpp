class Solution {
public:
    int firstStableIndex(vector<int>& a, int k) {
        int n=a.size();
        vector<int>x(n,a[0]),y(n,a[n-1]);

        for(int i=1;i<n;i++){
            x[i]=max(x[i-1],a[i]);
            y[n-1-i]=min(y[n-i],a[n-1-i]);
        }

        for(int i=0;i<n;i++) if(x[i]-y[i]<=k) return i;
        return -1;
    }
};
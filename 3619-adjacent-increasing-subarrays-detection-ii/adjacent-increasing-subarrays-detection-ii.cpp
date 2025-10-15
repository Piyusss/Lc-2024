class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& a) {
        int n=a.size(),res=0;

        vector<int>l(n+1),r(n+2);

        for(int i=1;i<=n;i++) l[i]=(i>1&&a[i-2]<a[i-1]) ? l[i-1]+1 : 1;
        for(int i=n;i;i--) r[i]=(i<n&&a[i-1]<a[i]) ? r[i+1]+1 : 1;
        for(int i=1;i<=n;i++) res=max(res,min(l[i-1],r[i]));

        return res;
    }
};
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& a) {
        int n=a.size();

        vector<int>p(n),s(n),r(n);

        for(int i=1;i<n;i++) p[i]=p[i-1]+a[i-1];
        for(int i=n-2;i>=0;i--) s[i]=s[i+1]+a[i+1];
        for(int i=0;i<n;i++) r[i]=abs(p[i]-s[i]);

        return r;
    }
};
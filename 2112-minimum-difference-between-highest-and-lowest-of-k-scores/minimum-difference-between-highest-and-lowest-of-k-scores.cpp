class Solution {
public:
    int minimumDifference(vector<int>&a,int k) {
        int n=a.size();
        if(n<k) return 0;

        sort(a.begin(),a.end());

        int r=INT_MAX;
        for(int i=0;i+k-1<n;i++) r=min(r,a[i+k-1]-a[i]);

        return r;
    }
};
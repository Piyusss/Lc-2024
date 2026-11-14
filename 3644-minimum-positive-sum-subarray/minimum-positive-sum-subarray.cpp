class Solution {
public:
    int minimumSumSubarray(vector<int>& a, int l, int r) {
        int n=a.size(),ans=INT_MAX;

        vector<int>p(n+1);
        for(int i=0;i<n;i++) p[i+1]=p[i]+a[i];

        for(int i=l;i<=r;i++){
            for(int j=i;j<=n;j++){
                int s=p[j]-p[j-i];
                if(s>0) ans=min(ans,s);
            }
        }

        return (ans==INT_MAX)?-1:ans;
    }
};
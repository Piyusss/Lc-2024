class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& a, int k) {
        int n=a.size(),h=0,t=0,j=n-1;

        long long ans=0,c=0;
        vector<int>d(n);

        for(int i=n-1;i>=0;i--){
            while(h<t && a[d[t-1]]<a[i]){
                int l=d[--t],r=h<t?d[t-1]:j+1;
                c+=1LL*(r-l)*(a[i]-a[l]);
            }

            d[t++]=i;

            while(c>k){
                c-=a[d[h]]-a[j];
                if(d[h]==j) h++;
                j--;
            }

            ans += j-i+1;
        }

        return ans;
    }
};
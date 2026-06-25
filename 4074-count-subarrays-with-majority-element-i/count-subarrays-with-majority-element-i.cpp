class Solution {
public:
    int countMajoritySubarrays(vector<int>& a,int t) {
        int n=a.size();

        vector<int>c(2*n+2);
        int s=n,x=0,r=0;
        c[s]=1;

        for(int i=0;i<n;i++){
            if(a[i]==t){
                x+=c[s];
                s++;
            }
            else{
                s--;
                x-=c[s];
            }

            r+=x;
            c[s]++;
        }

        return r;
    }
};
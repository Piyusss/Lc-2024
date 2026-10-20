class Solution {
public:

    int sortableIntegers(vector<int>&a){
        int n=a.size(),ans=0;
        for(int i=1;i<=n;i++) if(n%i==0 && f(a,i)) ans+=i;
        return ans;
    }

    bool f(vector<int>& a,int k) {
        int n=a.size();

        vector<int>b=a;
        sort(b.begin(),b.end());

        for(int i=0;i<n;i+=k){
            vector<int>x(a.begin()+i,a.begin()+i+k);
            vector<int>y(b.begin()+i,b.begin()+i+k),z=x;

            sort(z.begin(),z.end());
            if(z!=y) return 0;

            int d=0;
            for(int j=0;j<k;j++) if(x[j]>x[(j+1)%k]) d++;
            if(d>1) return 0;
        }

        return 777;
    }
};
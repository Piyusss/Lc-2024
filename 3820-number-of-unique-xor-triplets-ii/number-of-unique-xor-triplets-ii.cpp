class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        int m=*max_element(a.begin(),a.end());

        int n=1;
        while(n<=m) n<<=1;

        vector<bool>x(n),y(n),z(n);
        for(auto &i:a){
            x[i]=1;
            for(int j=0;j<n;j++) if(x[j]) y[i^j]=1;
        }

        for(auto &i:a) for(int j=0;j<n;j++) if(y[j]) z[i^j]=1;

        int ans=0;
        for(auto i:z) ans+=i;
        return ans;
    }
};
class Solution { 
public:

    int f(int i,int k,vector<int>&a){
        int l=i,r=a.size()-1,ans=i;

        while(l<=r){
            int m=l+(r-l)/2;
            if(a[m]<=1LL*k*a[i]){
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }

        return ans;
    }

    int minRemoval(vector<int>&a,int k) {
        sort(a.begin(),a.end());

        int n=a.size(),res=n-1;

        for(int i=0;i<n;i++){
            int j=f(i,k,a);
            res=min(res,i+n-j-1);
        }

        return res;
    }
};
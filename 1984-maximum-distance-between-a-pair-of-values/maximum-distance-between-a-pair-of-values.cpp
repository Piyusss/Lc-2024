class Solution {
public:
    int maxDistance(vector<int>& a,vector<int>& b) {
        int i=0,j=0,n=a.size(),m=b.size(),res=0;

        while(i<n && j<m){
            if(a[i]>b[j]) i++;
            else{
                if(i<=j) res=max(res,j-i);
                j++;
            }
        }

        return res;
    }
};
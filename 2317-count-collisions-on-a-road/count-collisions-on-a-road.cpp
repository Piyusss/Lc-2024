class Solution {
public:
    int countCollisions(string d) {
        int n=d.size(),ans=0,l=0,r=n-1; 

        while(l<n && d[l]=='L') l++;
        while(r>=l && d[r]=='R') r--;

        for(int i=l;i<=r;i++){
            if(d[i]!='S') ans++;
        }

        return ans;
    }
};
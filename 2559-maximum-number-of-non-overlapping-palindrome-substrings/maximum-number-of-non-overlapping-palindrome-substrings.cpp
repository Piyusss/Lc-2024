class Solution {
public:
    int maxPalindromes(string s,int k) {
        int n=s.size();

        if(k==1) return n;
        int ans=0;

        for(int i=0;i<=n-k;){
            int d=1;

            for(auto x:{k,k+1}){
                if(i+x<=n && equal(s.begin()+i,s.begin()+i+(x>>1),
                    s.rbegin()+(n-i-x))){
                    d=x;
                    ans++;
                    break;
                }
            }

            i+=d;
        }

        return ans;
    }
};
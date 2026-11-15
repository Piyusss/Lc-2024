const int M=1E9+7;

class Solution {
public:
    int numOfSubarrays(vector<int>& a) {
        int n=a.size(),o=0,e=1,s=0,ans=0;

        for(int i=0;i<n;i++){
            s+=a[i];

            if(s&1) ans=(ans+e)%M,o++;
            else ans=(ans+o)%M,e++;
        }

        return ans;
    }
};
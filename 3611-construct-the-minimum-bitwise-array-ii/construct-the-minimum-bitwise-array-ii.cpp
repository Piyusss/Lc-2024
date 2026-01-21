class Solution {
public:
    vector<int>minBitwiseArray(vector<int>& a) {
        int n=a.size();
        vector<int>r(n,-1);

        for(int i=0;i<n;i++){
            int x=a[i];
            if(x==2) continue;

            for(int b=0;b<32;b++){
                if(((x>>b)&1)==0){
                    r[i]=x^(1<<(b-1));
                    break;
                }
            }
        }

        return r;
    }
};
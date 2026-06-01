class Solution {
public:
    int minimumCost(vector<int>& a) {
        vector<int>f(101);

        for(auto &x:a) f[x]++;

        int c=0,r=0;
        for(int i=100;i>=0;i--){
            while(f[i]){
                c++;
                if(c%3) r+=i;
                f[i]--;
            }
        }

        return r;
    }
};
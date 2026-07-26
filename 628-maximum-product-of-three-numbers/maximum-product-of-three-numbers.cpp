class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();

        int m=INT_MIN,sm=INT_MIN,tm=INT_MIN;
        int mi=INT_MAX,smi=INT_MAX;

        for(int i=0;i<n;i++){
            int d=nums[i];

            if(d>m){
                tm=sm;
                sm=m;
                m=d;
            }
            else if(d>sm){
                tm=sm;
                sm=d;
            }
            else if(d>tm){
                tm=d;
            }

            if(d<mi){
                smi=mi;
                mi=d;
            }
            else if(d<smi){
                smi=d;
            }
        }

        return max(m*sm*tm,mi*smi*m);
    }
};
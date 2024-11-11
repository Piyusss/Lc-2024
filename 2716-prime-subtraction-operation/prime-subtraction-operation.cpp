class Solution {
public:

vector<bool>soe(int n){
    vector<bool>v(n+1,1);

    v[0]=v[1]=0;
    for(int p=2;p*p<=n;p++) if(v[p]) for(int i=p*p;i<=n;i+=p) v[i]=0;
    return v;

}

    bool primeSubOperation(vector<int>& nums){
        int n=nums.size();

        vector<bool>isPrime=soe(1E3);

        for(int i=n-2;i>=0;i-=1){
            if(nums[i+1]<=nums[i]){
                for(int p=2;p<nums[i];p++){
                    if(isPrime[p] && nums[i]-p < nums[i+1]){
                        nums[i]-=p;
                        break;
                    }
                }
                if(nums[i+1]<=nums[i])return 0;
            }
        }

        return 1;

    }
};
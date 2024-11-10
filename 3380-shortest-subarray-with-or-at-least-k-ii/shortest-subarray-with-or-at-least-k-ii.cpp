class Solution {
public:

void modify(vector<int>&bits,int howMuch,int val){
    for(int i=0;i<32;i++) if((1<<i) & val) bits[i]+=howMuch;
}

int bitwiseVal(vector<int>&bits){
    int res=0;
    for(int i=0;i<32;i++) if(bits[i]) res |= (1<<i);
    return res;
}

    int minimumSubarrayLength(vector<int>& nums, int k){
        int n=nums.size();

        int i=0,j=0,mini=INT_MAX;
        vector<int>bits(32,0);

        while(j<n){
            modify(bits,1,nums[j]);

            while(i<=j && bitwiseVal(bits)>=k){
                mini=min(mini,j-i+1);
                modify(bits,-1,nums[i]);
                i+=1;
            }

            j+=1;
        }

        return mini!=INT_MAX ? mini : -1;
        
    }
};
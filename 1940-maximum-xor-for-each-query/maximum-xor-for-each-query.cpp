class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximBit) {
        int n=nums.size();

        int flag=0;
        vector<int>prefixXor(n);

        for(int i=0;i<n;i++){
            prefixXor[i]=nums[i]^flag;
            flag=prefixXor[i];
        }

        reverse(prefixXor.begin(),prefixXor.end());

        int mask= pow(2,maximBit)-1;
        int qRes=0;

        vector<int>res;
        for(int i=0;i<n;i++){
            int invK=prefixXor[i] ^ mask;
            res.push_back(invK);
        }

        return res;
    }
};
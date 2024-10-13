class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();

        vector<int>res;
        for(auto &it:nums){
            if(!(it&1)) res.push_back(-1);
            else{
                for(int i=0;i<=it;i++){
                    if( (i | (i+1)) == it){
                        res.push_back(i);
                        break;
                    }
                }
            }
        }

        return res;
    }
};
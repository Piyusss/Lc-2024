class Solution {
public:
    string longestCommonPrefix(vector<string>& nums) {
        int n=nums.size();
        //now
        int ans=0;string res="";
        for(int i=0;i<nums[0].size();i++){
            set<char>temp;
            for(auto it:nums)temp.insert(it[i]);
            if(temp.size()==1)res+=nums[0][i];
            else break;
        }
        //now
        return res;
    }
};
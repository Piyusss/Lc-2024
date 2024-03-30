class Solution {
public:
    string longestCommonPrefix(vector<string>& nums) {
        int n=nums.size();
        //now
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int size=nums[i].size();
            mini=min(mini,size);
        }
        //now
        int ans=0;
        set<char>temp;
        for(int i=0;i<mini;i++){
            for(auto it:nums){
                temp.insert(it[i]);
            }
            if(temp.size()==1){
                ans++;
                temp.clear();
            }
            else break;
        }
        //now
        string res="";
        for(int i=0;i<ans;i++)res+=nums[0][i];
        return res;
    }
};
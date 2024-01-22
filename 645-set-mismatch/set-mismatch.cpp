class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        //now
        for(auto it:nums){
            if(count(nums.begin(),nums.end(),it)==2){
                ans.push_back(it);break;
            }
        }
        //now
        int cnt=1;
        while(cnt<=nums.size()){
            if(count(nums.begin(),nums.end(),cnt)==0){
                ans.push_back(cnt);break;
            }
            cnt++;
        }
        return ans;
    }
};
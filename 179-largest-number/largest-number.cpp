class Solution {
public:

static bool comp(int a,int b){
    string x=to_string(a);
    string y=to_string(b);
    return (x+y)>(y+x);
}
    string largestNumber(vector<int>& nums){
        sort(nums.begin(),nums.end(),comp);
        if(nums[0]==0)return "0";

        string res="";
        for(auto &it:nums)res+=to_string(it);
        return res;
    }
};
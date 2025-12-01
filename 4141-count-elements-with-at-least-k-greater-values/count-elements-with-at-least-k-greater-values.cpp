class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();

        if(k==0) return n;

        vector<int>temp=nums;
        sort(temp.begin(),temp.end());

        int threshold=temp[n-k];

        int cnt=0;
        for(auto &c:nums) if(c<threshold) cnt++;
        return cnt;
    }
};
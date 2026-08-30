class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        int minIdx=min_element(nums.begin(),nums.end())-nums.begin();
        int maxIdx=max_element(nums.begin(),nums.end())-nums.begin();

        if(!(maxIdx<minIdx)) swap(minIdx,maxIdx);
        return min(maxIdx+1+n-minIdx,min(minIdx+1,n-maxIdx));
    }
};
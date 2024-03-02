class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>v;
        int num=-1;
        for(int i=0 ; i<nums.size() ; i++){
            int num=nums.at(i)*nums.at(i);
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        return v;
    }
};
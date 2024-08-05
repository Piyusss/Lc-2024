class Solution {
public:
void f(int ind,vector<int>ds,int n,vector<int>nums,set<vector<int>>&store){
    if(ind==n){
        store.insert(ds);
        return;
    }

    f(ind+1,ds,n,nums,store);

    ds.push_back(nums[ind]);
    f(ind+1,ds,n,nums,store);
    ds.pop_back();

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int>ds;
        set<vector<int>>store;
        sort(nums.begin(),nums.end());

        f(0,ds,n,nums,store);

        vector<vector<int>>final;
        for(auto it:store)final.push_back(it);
        return final;
    }
};
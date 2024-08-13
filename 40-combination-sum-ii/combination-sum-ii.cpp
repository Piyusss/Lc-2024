class Solution {
public:
void f(int ind,int target,vector<int>&ds,vector<vector<int>>&ans,vector<int>arr){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    //now
    for(int i=ind;i<arr.size();i++){
        if(arr[i]>target)break;
        if(i>ind && arr[i]==arr[i-1])continue;
        ds.push_back(arr[i]);
        f(i+1,target-arr[i],ds,ans,arr);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,target,ds,ans,arr);
        return ans;
    }
};
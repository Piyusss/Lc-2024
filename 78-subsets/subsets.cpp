class Solution {
public:

int n;
vector<vector<int>>ans;
vector<int>temp;

void f(int ind,vector<int>nums){
	if(ind==n){
		ans.push_back(temp);
        return;
	}
	
	//not-pick
	f(ind+1,nums);

	//pick
    temp.push_back(nums[ind]);
	f(ind+1,nums);
	temp.pop_back();

}
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        f(0,nums);
        return ans;
    }
};
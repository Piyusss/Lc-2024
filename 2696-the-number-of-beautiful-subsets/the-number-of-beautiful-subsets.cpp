class Solution {
public:

int on;
int cnt=0;
unordered_map<int,int>mp;

void f(int ind,vector<int>&nums,int k){
    if(ind==on)return;
	
	//not-pick
	f(ind+1,nums,k);

	//pick
    if(!mp[nums[ind]+k]  &&  !mp[nums[ind]-k] ){
        mp[nums[ind]]++;
        f(ind+1,nums,k);
        cnt++;
        mp[nums[ind]]--;
    }

}
    int beautifulSubsets(vector<int>& nums, int k){
        on=nums.size();
        f(0,nums,k);
        return cnt;
    }
};
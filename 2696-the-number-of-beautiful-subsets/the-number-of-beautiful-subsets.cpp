class Solution {
public:

int on;
int cnt;
unordered_map<int,int>mp;

void f(int ind,vector<int>&nums,int k){
    if(ind>=on){
        cnt++;
        return;
    }
	
	//not-pick
	f(ind+1,nums,k);

	//pick
    if(!mp[nums[ind]+k]  &&  !mp[nums[ind]-k] ){
        mp[nums[ind]]++;
        f(ind+1,nums,k);
        mp[nums[ind]]--;
    }

}
    int beautifulSubsets(vector<int>& nums, int k){
        cnt=0;
        on=nums.size();
        f(0,nums,k);
        return cnt-1;
    }
};
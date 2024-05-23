class Solution {
public:

int on;
int cnt;


void f(int ind,vector<int>&nums,int k,unordered_map<int,int>&mp){
    if(ind>=on){
        cnt++;
        return;
    }
	
	//not-pick
	f(ind+1,nums,k,mp);

	//pick
    if(!mp[nums[ind]+k]  &&  !mp[nums[ind]-k] ){
        mp[nums[ind]]++;
        f(ind+1,nums,k,mp);
        mp[nums[ind]]--;
    }

}
    int beautifulSubsets(vector<int>& nums, int k){
        cnt=0;
        on=nums.size();
        unordered_map<int,int>mp;
        f(0,nums,k,mp);
        return cnt-1;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        int maxi=1;
        vector<int>dp(n+5,1);
        vector<int>hash(n+1);
        int lastIdx=0;

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(1+dp[j]>dp[i]){
                        dp[i]=1+dp[j];
                        hash[i]=j;
                        lastIdx=i;
                    }
                }
            }
            maxi=max(maxi,dp[i]);
        }

        
//PRINT
        vector<int>temp;
		temp.push_back(nums[lastIdx]);
        while(hash[lastIdx]!=lastIdx){
    		lastIdx=hash[lastIdx];
    		temp.push_back(nums[lastIdx]);
    	}
    	reverse(temp.begin(),temp.end());
        for(auto it:temp)cout<<it<<" ";
        cout<<endl;
//PRINT

        return maxi;
    }
};
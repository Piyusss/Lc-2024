class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        //subsequence has order
        //subset has no order
        int n=arr.size();
        vector<int>dp(n,1),hash(n);
        sort(arr.begin(),arr.end());
        int maxi=1;int lastIndex=0;
        for(int i=0;i<n;i++){
			hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[i]%arr[prev]==0
				&& 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
					hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
				maxi=dp[i];
				lastIndex=i;
			}
        }
		vector<int>temp;
		temp.push_back(arr[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
		lastIndex=hash[lastIndex];
		temp.push_back(arr[lastIndex]);
	}
	reverse(temp.begin(),temp.end());
	return temp;
    }
};
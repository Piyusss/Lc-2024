class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();

        vector<int>freq(101,0);
        int maxi=0;

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            maxi=max(maxi,freq[nums[i]]);
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(freq[nums[i]] == maxi) cnt++;
        }

        return cnt;
    }
};
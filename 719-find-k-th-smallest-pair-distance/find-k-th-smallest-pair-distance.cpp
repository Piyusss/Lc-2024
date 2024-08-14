class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>dis(*max_element(nums.begin(),nums.end())+1);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dif=abs(nums[i]-nums[j]);
                dis[dif]++;
            }
        }

        for(int i=0;i<dis.size();i++){
            k-=dis[i];
            if(k<=0)return i;
        }
        return -1;
    }
};
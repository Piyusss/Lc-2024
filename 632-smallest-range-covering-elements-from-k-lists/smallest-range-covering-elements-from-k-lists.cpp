class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums){
        int n=nums.size();

        vector<int>res={-1000000,1000000};
        vector<int>info(n,0);

        while(1){
            int minEl=INT_MAX;
            int maxEl=INT_MIN;
            int minElIdx=0;

            for(int i=0;i<n;i++){
                int listElIdx=info[i]; //pointer of a list

                if(nums[i][listElIdx] < minEl){
                    minEl=nums[i][listElIdx];
                    minElIdx=i;
                }
                maxEl=max(maxEl,nums[i][listElIdx]);
            }

            if(maxEl-minEl < res[1]-res[0]){
                res[0]=minEl;
                res[1]=maxEl;
            }

            int newElIdxafterInc=info[minElIdx]+1;
            if(newElIdxafterInc >= nums[minElIdx].size()) break;
            info[minElIdx]=newElIdxafterInc;
        }

        return res;

    }
};
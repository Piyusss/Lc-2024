class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2){
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        //now
        map<int,int>mp1,mp2;
        for(int i=0;i<nums1.size();i++)mp1[nums1[i]]=1;
        //now
        for(int i=0;i<nums2.size();i++){
            if(mp1[nums2[i]]==1)return nums2[i];
        }
        return -1;
    }
};
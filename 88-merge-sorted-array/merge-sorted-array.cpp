class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {

        int l=0,r=0,idx=0;
        vector<int>nums3(n+m);
        // //
        // while(nums1[nums1.size()-1]==0){
        //     nums1.pop_back();
        // }
        // //
        vector<int>nums1copy;
        for(int i=0;i<n;i++)nums1copy.push_back(nums1[i]);

        while(l<n && r<m){
            if(nums1copy[l]<=nums2[r]){
                nums3[idx]=nums1copy[l];
                l++;idx++;
            }
            else{
                nums3[idx]=nums2[r];
                r++;idx++;
            }
        }

        while(l<n)nums3[idx++]=nums1copy[l++];
        while(r<m)nums3[idx++]=nums2[r++];

        // while(nums3[0]==0)nums3.erase(nums3.begin());

        for(int i=0;i<n+m;i++){
            nums1[i]=nums3[i];
            // else nums2[i-n]=nums3[i];
        }
    }
};
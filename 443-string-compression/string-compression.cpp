class Solution {
public:
    int compress(vector<char>& nums) {
        int n=nums.size();

        int idx=0;
        int i=0;
        while(i<n){
            char cur_ch=nums[i];
            int cnt=0;

            while(i<n){
                if(nums[i]==cur_ch){
                    cnt++;
                    i++;
                }
                else break;
            }
                nums[idx]=cur_ch;
                idx++;
                if(cnt>1){
                    string temp=to_string(cnt);
                    for(int j=0;j<temp.size();j++){
                        nums[idx]=temp[j];
                        idx++;
                    }
                }
        }
        return idx;
    }
};
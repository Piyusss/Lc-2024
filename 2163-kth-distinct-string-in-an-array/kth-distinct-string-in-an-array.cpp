class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int cnt=0;
        for(auto it:arr){
            if(count(arr.begin(),arr.end(),it)==1){
                cnt++;
                if(cnt==k)return it;
            }
        }
        return "";
    }
};
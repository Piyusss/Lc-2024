class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        int cnt_of_ones=0;
        for(auto it:s)if(it=='1')cnt_of_ones++;
        int cnt_of_zeros=n-cnt_of_ones;
        //now
        string ans="";
        for(int i=0;i<cnt_of_zeros;i++)ans+='0';
        ans.push_back('1');
        for(int i=2;i<=cnt_of_ones;i++){
            ans.insert(ans.begin(),'1');
        }
        return ans;
    }
};
class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.size();

        string ans="",temp;
        int cnt=0;

        for(int i=0;i<n;i+=k){
            cnt=0;
            temp=s.substr(i,k);
            for(int i=0;i<k;i++) cnt=(cnt+(temp[i]-'a'))%26;
            ans+=(cnt+'a');
        }

        return ans;
    }
};
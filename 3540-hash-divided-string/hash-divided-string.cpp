class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.size();

        string ans="";

        for(int i=0;i<n;i+=k){
            string temp=s.substr(i,k);
            int cnt=0;
            for(int i=0;i<temp.size();i++) cnt=(cnt+(temp[i]-'a'))%26;
            ans+=(cnt+'a');
        }

        return ans;
    }
};
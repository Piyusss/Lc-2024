class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.size();

        string ans="";

        for(int i=0;i<n;i+=k){
            string temp=s.substr(i,k);
            int cnt=0;
            for(int i=0;i<temp.size();i++){
                cnt+=temp[i]-'a';
            }
            cnt=cnt%26;
            char ch=cnt+'a';
            string flag="";
            flag+=ch;
            ans+=flag;
        }

        return ans;
    }
};
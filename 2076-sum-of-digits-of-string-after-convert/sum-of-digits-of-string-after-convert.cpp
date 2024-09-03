class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.size();
        string f="";

        for(int i=0;i<n;i++) f+=to_string(s[i]-'a'+1);
        cout<<f;

        int ans=0,cnt=0;

        for(int i=0;i<k;i++){
            cnt=0;
            for(int j=0;j<f.size();j++) cnt+=f[j]-'0';
            ans=cnt;
            f=to_string(cnt);
        }

        return ans;
    }
};
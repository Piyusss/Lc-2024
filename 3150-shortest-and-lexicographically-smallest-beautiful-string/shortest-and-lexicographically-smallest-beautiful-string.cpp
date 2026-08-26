class Solution {
public:
    string shortestBeautifulSubstring(string s,int k) {
        int n=s.size(),i=0,c=0;
        string r="";

        for(int j=0;j<n;j++){
            c+=s[j]-'0';

            while(c>k){
                c-=s[i]-'0';
                i+=1;
            }

            if(c==k){
                while(s[i]=='0') i+=1;
                string x=s.substr(i,j-i+1);
                if(r.empty()||x.size()<r.size() || x.size()==r.size()&&x<r) r=x;
            }
        }

        return r;
    }
};
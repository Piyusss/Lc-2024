class Solution {
public:

    string ans;
    int n;

    bool f(string &s,string &t,vector<int>&c,int i,bool g){
        if(i==n/2){
            if(g){
                ans=s;
                return 1;
            }

            string x=s;

            if(n%2){
                for(int j=0;j<26;j++){
                    if(c[j]&1){
                        x+=char('a'+j);
                        break;
                    }
                }
            }

            string r=s;
            reverse(r.begin(),r.end());
            x+=r;

            if(x>t){
                ans=s;
                return 1;
            }

            return 0;
        }

        for(int j=0;j<26;j++){
            if(c[j]<2) continue;

            char x='a'+j;
            if(!g&&x<t[i]) continue;

            s+=x;
            c[j]-=2;

            if(f(s,t,c,i+1,g||x>t[i])) return 1;
            s.pop_back();
            c[j]+=2;
        }

        return 0;
    }

    string lexPalindromicPermutation(string s,string t) {
        n=s.size();
        ans="";

        vector<int>c(26);
        for(auto &x:s) c[x-'a']++;

        int o=0;
        char m='#';

        for(int i=0;i<26;i++){
            if(c[i]&1){
                o++;
                m='a'+i;
            }
        }

        if(o>1) return "";

        string x;
        if(n==1) return s>t?s:"";

        f(x,t,c,0,0);
        if(ans=="") return "";

        string r=ans;
        reverse(r.begin(),r.end());

        if(n&1) ans+=m;
        ans+=r;

        return ans>t?ans:"";
    }
};
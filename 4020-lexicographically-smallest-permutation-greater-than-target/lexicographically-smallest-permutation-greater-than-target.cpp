class Solution {
public:

    string ans;
    void f(int i,string&s,vector<int>&c){
        int n=s.size();

        if(i==n) return;
        int x=s[i]-'a';

        if(c[x]){
            c[x]--;
            f(i+1,s,c);
            c[x]++;
        }

        for(int j=x+1;j<26;j++){
            if(c[j]){
                c[j]--;
                string t=s.substr(0,i)+char('a'+j);

                for(int k=0;k<26;k++){
                    while(c[k]){
                        t+=char('a'+k);
                        c[k]--;
                    }
                }
                ans=min(ans,t);
                return;
            }
        }
    }

    string lexGreaterPermutation(string s,string t){
        sort(s.rbegin(),s.rend());
        if(s<=t) return "";
        ans=s;

        vector<int>c(26);
        for(auto &x:s) c[x-'a']++;

        f(0,t,c);
        return ans;
    }
};
class Solution {
public:
    
    int f[26],l[26],c[26]={};
    
    vector<string> maxNumOfSubstrings(string s) {
        vector<int>v;

        fill(f,f+26,-1);
        fill(l,l+26,-1);

        for(int i=0;i<s.size();i++){
            int x=s[i]-'a';

            if(!c[x]){
                f[x]=i;
                v.push_back(x);
            }

            c[x]++;
            l[x]=i;
        }

        vector<string>ans;
        deque<array<int,3>>q;

        for(auto &x:v){
            q.push_front({f[x],l[x],c[x]});
            int a=INT_MAX,b=INT_MIN,t=0;

            for(auto &z:q){
                t+=z[2];
                a=min(a,z[0]);
                b=max(b,z[1]);

                if(t==b-a+1) break;
            }

            if(t==b-a+1){
                ans.push_back(s.substr(a,b-a+1));
                q.clear();
            }
        }

        return ans;
    }
};
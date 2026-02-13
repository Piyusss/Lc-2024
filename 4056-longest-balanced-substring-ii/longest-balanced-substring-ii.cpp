class Solution {
public:
    vector<pair<char,char>>p={{'a','b'},{'a','c'},{'b','c'}};

    int longestBalanced(string s) {
        int n=s.size(),res=1,cur=1;

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])cur++;
            else cur=1;
            res=max(res,cur);
        }

        for(auto &q:p){
            unordered_map<int,int>mp;
            mp[0]=-1;
            int x=0,y=0;

            for(int i=0;i<n;i++){
                if(s[i]!=q.first && s[i]!=q.second){
                    mp.clear();
                    mp[0]=i;
                    x=y=0;
                    continue;
                }

                if(s[i]==q.first)x++;
                else y++;

                int d=x-y;
                if(mp.count(d))res=max(res,i-mp[d]);
                else mp[d]=i;
            }
        }

        unordered_map<string,int>mp2;
        mp2["0#0"]=-1;
        int a=0,b=0,c=0;

        for(int i=0;i<n;i++){
            if(s[i]=='a')a++;
            else if(s[i]=='b')b++;
            else c++;

            string k=to_string(b-a)+"#"+to_string(c-a);

            if(mp2.count(k))res=max(res,i-mp2[k]);
            else mp2[k]=i;
        }
        
        return res;
    }
};
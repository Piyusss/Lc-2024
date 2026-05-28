struct Node {
    int ch[26];
    int len,idx;

    Node(){
        fill(ch,ch+26,-1);
        len=1e9;
        idx=1e9;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& a,vector<string>& q) {
        vector<Node>t(1);

        for(int i=0;i<a.size();i++){
            int n=a[i].size(),u=0;

            if(n<t[u].len || (n==t[u].len && i<t[u].idx)){
                t[u].len=n;
                t[u].idx=i;
            }

            for(int j=n-1;j>=0;j--){
                int c=a[i][j]-'a';

                if(t[u].ch[c]==-1){
                    t[u].ch[c]=t.size();
                    t.push_back(Node());
                }

                u=t[u].ch[c];

                if(n<t[u].len || (n==t[u].len && i<t[u].idx)){
                    t[u].len=n;
                    t[u].idx=i;
                }
            }
        }

        vector<int>r;

        for(auto &s:q){
            int u=0;

            for(int j=s.size()-1;j>=0;j--){
                int c=s[j]-'a';
                if(t[u].ch[c]==-1) break;
                u=t[u].ch[c];
            }

            r.push_back(t[u].idx);
        }

        return r;
    }
};
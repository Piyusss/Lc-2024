class Solution {
public:
bool f(char ch,vector<char>&v){
    if(find(v.begin(),v.end(),ch)!=v.end())return 1;
    v.push_back(ch);
    return 0;
}
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        //now
        unordered_map<char,char>mp;
        vector<char>flag;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                if(mp[s[i]]==NULL){
                    if(!f(t[i],flag)){
                        mp[s[i]]=t[i];
                        s[i]=t[i];
                    }
                }
                else s[i]=mp[s[i]];
            }
            else{
                if(mp[s[i]]!=NULL){
                    s[i]=mp[s[i]];
                }
                else{
                    if(!f(t[i],flag))mp[s[i]]=t[i];
                    else return 0;
                }
            }
        }
        //now
        if(s==t)return 1;
        return 0;
    }
};
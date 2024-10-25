class Solution {
public:

static bool comp(string &a,string &b){
    return a.size() < b.size();
}
    vector<string> removeSubfolders(vector<string>& folder){
        int n=folder.size();

        unordered_map<string,int>mp;
        sort(folder.begin(),folder.end(),comp);

        for(auto &it:folder) cout<<it<<" ";

        vector<string>res;
        for(int i=0;i<n;i++){
            string s=folder[i];
            int flag=0;

            for(int j=1;j<=s.size();j++){
                string req=s.substr(0,j);
                if(j==s.size() || s[j]=='/'){
                    if(mp.find(req)!=mp.end()){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0){
                res.push_back(s);
                mp[s]=1;
            }
        }

        return res;

    }
};
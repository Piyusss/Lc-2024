class Solution {
public:

static bool comp(string &a,string &b){
    return a<b;
}
    vector<int> lexicalOrder(int n) {
        vector<string>v;
        for(int i=1;i<=n;i++)v.push_back(to_string(i));

        sort(v.begin(),v.end(),comp);
        
        vector<int>res;
        for(auto &it:v)res.push_back(stoi(it));

        return res;
    }
};
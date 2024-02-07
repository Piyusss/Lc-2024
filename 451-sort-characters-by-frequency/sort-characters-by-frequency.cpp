class Solution {
public:
static bool sortByValue(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto it:s)mp[it]++;
        //now
        string ans="";
        map<int,char>mp2;
        for(auto it:mp){
            char ch=it.first;
            int freq=it.second;
        }
        //now
        vector<pair<int,int>>vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),sortByValue);
        for(auto p:vec) {
            int freq=p.second;
            char ch=p.first;
            while(freq--)ans+=ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
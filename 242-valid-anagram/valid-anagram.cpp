class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();

        if(n!=m) return 0;

        unordered_map<char,int>mp;
        for(auto &c:s) mp[c]++;

        for(auto &c:t){
            if(mp.find(c) != mp.end()){
                mp[c]--;
            }
            else return 0;

            if(mp[c]==0) mp.erase(c);
        }

        return 1;
    }
};
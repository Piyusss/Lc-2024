class Solution {
public:
    int minSteps(string s,string t){
        int count[26]={0};
        for(int i=0;i<s.size();i++){
            count[t[i]-'a']++;
            count[s[i]-'a']--;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans += max(0, count[i]);
        }
        return ans;
    }
};
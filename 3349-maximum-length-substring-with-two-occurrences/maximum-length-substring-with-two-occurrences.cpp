class Solution {
public:
    int maximumLengthSubstring(string s){
        int n=s.size();unordered_map<char,int>mp;int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(mp[s[j]]>2){
                    break;
                }
                else maxi=max(maxi,j-i+1);
            }
            mp.clear();
        }
        return maxi;
    }
};
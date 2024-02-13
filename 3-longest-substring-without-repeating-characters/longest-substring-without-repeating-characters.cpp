class Solution {
public:
    int lengthOfLongestSubstring(string st) {
    long long i=0;long long j=0;long long n=st.length();
    unordered_map<char,long long>mp;long long maxi=0;
    while(j<n){
        mp[st[j]]++;
        if(mp[st[j]]==1){
            maxi=max(maxi,j-i+1);
        }
        else if(mp[st[j]]==2){
            while(mp[st[j]]==2){
                mp[st[i]]--;
                i++;
                if(mp[st[i]]==0){
                    mp.erase(st[i]);
                }
            }
        }
        j++;
    }
    return maxi;
    }
};
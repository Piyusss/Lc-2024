class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string target="balloon";

        int m=target.size();
        int n=text.size();

        vector<int>freq(26,0),reqFreq(26,0);

        for(int i=0;i<n;i++) freq[text[i]-'a']++;
        for(int i=0;i<m;i++) reqFreq[target[i]-'a']++;

        int mini=INT_MAX;

        for(auto &c:target){
            if(freq[c-'a']<reqFreq[c-'a']) return 0;
            mini=min(mini,freq[c-'a']/reqFreq[c-'a']);
        }

        return mini;
    }
};
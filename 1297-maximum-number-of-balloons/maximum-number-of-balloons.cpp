class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        vector<int>freq(26,0);

        for(int i=0;i<n;i++) freq[text[i]-'a']++;

        int freqB=freq['b'-'a'];
        int freqA=freq['a'-'a'];
        int freqL=freq['l'-'a'];
        int freqO=freq['o'-'a'];
        int freqN=freq['n'-'a'];

        cout<<freqB<<" "<<freqA<<" "<<freqL<<" "<<freqO<<" "<<freqN;

        int mini=INT_MAX;
        mini=min(mini,min(freqB,min(freqA,min(freqL/2,min(freqO/2,freqN)))));

        if(freqB<1 || freqA<1 || freqL<2 || freqO<2 || freqN<1) return 0;
        return mini;
    }
};
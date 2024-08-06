class Solution {
public:

    void f(string &word){
        unordered_map<char, int>mp;
        for( char &ch : word)mp[ch]++;
        auto comp=[&]( char &ch1,  char &ch2){
            return mp[ch1]>mp[ch2];
        };
        sort(begin(word),end(word), comp);
    }
    

    int minimumPushes(string word) {
        if(word.length() <= 8)return word.length();
        f(word);
        unordered_map<int,unordered_set<char>>myMap;
        unordered_map<char,pair<int,int>>mp;
        
        int result=0,assign=2;
        for(char &ch:word) {
            if(assign>9)assign=2;
            if(mp.find(ch)==mp.end()) {
                myMap[assign].insert(ch);
                mp[ch]={assign,(int)myMap[assign].size()};

                result+=mp[ch].second;
                assign++;
            }
            else result+=mp[ch].second;
        }
        return result;
    }
};
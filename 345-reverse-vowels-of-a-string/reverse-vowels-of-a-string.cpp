class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        vector<char>vc;
        vector<int>vi;

        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'
             || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                vc.push_back(s[i]);
                vi.push_back(i);
            }
        }
        //now
        reverse(vi.begin(),vi.end());
        //now
        for(auto it:vi){
            s[it]=vc.front();
            vc.erase(vc.begin());
        }
        return s;
    }
};
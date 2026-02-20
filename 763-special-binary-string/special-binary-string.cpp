class Solution {
public:

    string makeLargestSpecial(string s) {
        int bal=0;
        vector<string>v;

        for(int i=0,j=0;j<s.size();j++){
            bal+=(s[j]=='1')?1:-1;

            if(bal==0){
                string t=makeLargestSpecial(s.substr(i+1,j-i-1));
                v.push_back("1"+t+"0");
                i=j+1;
            }
        }

        sort(v.begin(),v.end(),greater<string>());

        string r;
        for(auto &x:v) r += x;
        return r;
    }
};
class Solution {
public:
    vector<int> separateDigits(vector<int>& a) {
        vector<int>r;

        for(auto &x:a){
            if(x<10) r.push_back(x);
            else{
                string s=to_string(x);
                for(auto &c:s) r.push_back(c-'0');
            }
        }

        return r;
    }
};
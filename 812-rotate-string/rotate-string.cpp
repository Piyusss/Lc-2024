class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();

        for(int i=0;i<n;i++){
            s.push_back(s[0]);
            s.erase(0,1);
            if(s==goal) return 1;
        }

        return 0;

    }
};
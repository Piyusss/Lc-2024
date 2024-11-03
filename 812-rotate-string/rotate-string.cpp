class Solution {
public:
    bool rotateString(string s, string goal){
        int n=s.size();
        int m=goal.size();

        if(m!=n) return 0;

        s+=s;
        if(s.find(goal) != string::npos) return 1;

        return 0;

    }
};
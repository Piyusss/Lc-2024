class Solution {
public:
    bool rotateString(string s, string goal){
        int n=s.size();
        int m=goal.size();

        if(m<n) return 0;

        s+=s;
        for(int i=0;i<n;i++){
            if(s.substr(i,m)==goal) return 1;
        }

        return 0;

    }
};
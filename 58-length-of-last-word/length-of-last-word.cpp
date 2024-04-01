class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx=s.find_last_not_of(' ')+1;
        s.erase(idx);
        int idx2=s.find_last_of(' ');
        return idx2==string::npos?s.size():s.size()-idx2-1;
    }
};
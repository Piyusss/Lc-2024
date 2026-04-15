class Solution {
public:
    int closestTarget(vector<string>& w,string t,int s) {
        int n=w.size();
        for(int i=0;i<n;i++) if(w[(s+i)%n]==t || w[(s-i+n)%n]==t) return i;
        return -1;
    }
};
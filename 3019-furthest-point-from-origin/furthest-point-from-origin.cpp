class Solution {
public:
    int furthestDistanceFromOrigin(string m) {
        int c=0,u=0,n=m.size();

        for(int i=0;i<n;i++){
            if(m[i]=='_') u++;
            if(m[i]=='L') c--;
            if(m[i]=='R') c++;
        }

        return abs(c)+u;
    }
};
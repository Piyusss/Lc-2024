class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int r=0,p=0;

        for(auto &it:bank){
            int c=count(it.begin(),it.end(),'1');

            if(c>=1){
                r += c*p;
                p=c;
            }
        }

        return r;
    }
};
class Solution {
public:
    vector<string> twoEditWords(vector<string>& q,vector<string>& d) {
        vector<string>r;

        for(auto &x:q){
            for(auto &y:d){
                int c=0;
                for(int i=0;i<x.size();i++){
                    if(x[i]!=y[i]){
                        c++;
                        if(c>2) break;
                    }
                }

                if(c<=2){
                    r.push_back(x);
                    break;
                }
            }
        }

        return r;
    }
};
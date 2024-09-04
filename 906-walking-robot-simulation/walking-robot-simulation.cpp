class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>st;

        for(auto &it:obstacles){
            st.insert(to_string(it[0])+"_"+to_string(it[1]));
        }

        int x=0,y=0,maxi=0;
        pair<int,int>p={0,1};

        for(auto &it:commands){
            if(it==-2) p={-p.second,p.first};
            else if(it==-1) p={p.second,-p.first};
            else{
                for(int i=1;i<=it;i++){
                    int newX= x + p.first;
                    int newY= y + p.second;

                    if(st.find(to_string(newX) + "_" + to_string(newY)) != st.end())break;

                    x=newX;
                    y=newY;
                }

                maxi=max(maxi,x*x + y*y);
            }
        }

        return maxi;
    }
};
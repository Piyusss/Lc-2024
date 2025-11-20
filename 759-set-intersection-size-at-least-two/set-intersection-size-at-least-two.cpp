class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& v) {

        sort(v.begin(),v.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1] || (a[1]==b[1]&&a[0]>b[0]);
        });

        int res=0,x=-1,y=-1;

        for(auto &p:v){
            if(p[0]<=x)continue;

            if(p[0]>y){
                res+=2;
                y=p[1];
                x=y-1;
            }
            else{
                res++;
                x=y;
                y=p[1];
            }
        }

        return res;
    }
};
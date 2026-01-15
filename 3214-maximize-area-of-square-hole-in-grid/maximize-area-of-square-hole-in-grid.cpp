class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());

        int a=1,b=1,x=1,y=1;

        for(int i=0;i+1<h.size();i++){
            if(h[i]+1==h[i+1]) x++;
            else{
                a=max(a,x);
                x=1;
            }
        }

        a=max(a,x);

        for(int i=0;i<v.size()-1;i++){
            if(v[i]+1==v[i+1]) y++;
            else{
                b=max(b,y);
                y=1;
            }
        }

        b=max(b,y);
        int k=min(a+1,b+1);

        return k*k;
    }
};
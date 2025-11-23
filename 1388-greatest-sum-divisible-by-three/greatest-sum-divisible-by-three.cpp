class Solution {
public:
    int maxSumDivThree(vector<int>& a) {
        vector<int>r1,r2;
        int s=0;

        for(int &x:a){
            s+=x;
            if(x%3==1) r1.push_back(x);
            else if(x%3==2) r2.push_back(x);
        }

        if(s%3==0)return s;

        sort(r1.begin(),r1.end());
        sort(r2.begin(),r2.end());

        int res=0;
        if(s%3==1){
            if(!r1.empty()) res=max(res,s-r1[0]);
            if(r2.size()>1) res=max(res,s-r2[0]-r2[1]);
        }
        else{
            if(!r2.empty()) res=max(res,s-r2[0]);
            if(r1.size()>1) res=max(res,s-r1[0]-r1[1]);
        }

        return res;
    }
};
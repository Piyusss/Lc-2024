class Solution {
public:
    vector<int> pivotArray(vector<int>& a,int p) {
        int n=a.size();

        vector<int>r(n,p);
        int l=0,h=n-1;

        for(auto &x:a){
            if(x<p) r[l++]=x;
            else if(x>p) r[h--]=x;
        }

        l=h+1;
        h=n-1;

        while(l<h){
            swap(r[l],r[h]);
            l++;
            h--;
        }

        return r;
    }
};
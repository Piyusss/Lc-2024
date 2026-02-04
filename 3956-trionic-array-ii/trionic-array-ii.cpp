using ll=long long;

class Solution {
public:

    long long maxSumTrionic(vector<int>&a) {
        int n=a.size();
        ll res=LLONG_MIN;
        int i=0;

        while(i<n-3){
            if(a[i]<a[i+1]){
                ll cur=0;
                int x=i;

                while(x+1<n && a[x]<a[x+1]) x++;
                int y=x;

                while(y+1<n && a[y]>a[y+1]){
                    cur+=a[y];
                    y++;
                }

                i=y;
                cur+=a[y];
                
                x--;
                cur+=a[x];

                while(x>0 && a[x-1]<a[x] && a[x-1]>0){
                    x--;
                    cur+=a[x];
                }

                y++;
                while(y<n && a[y-1]<a[y]){
                    cur+=a[y];
                    res=max(res,cur);
                    y++;
                }
            }
            else i++;
        }

        return res;
    }
};
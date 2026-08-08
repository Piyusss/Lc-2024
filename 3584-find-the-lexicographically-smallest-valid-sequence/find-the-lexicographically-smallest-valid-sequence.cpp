class Solution {
public:
    vector<int> validSequence(string a,string b) {
        int n=a.size(),m=b.size();

        vector<int>p(n);
        for(int i=n-1,j=m-1;i>=0;i--){
            if(i<n-1) p[i]=p[i+1];
            if(j>=0 && a[i]==b[j]){
                p[i]++;
                j--;
            }
        }

        vector<int>r(m,-1);
        int c=0;

        for(int i=0,j=0;i<n && j<m;i++){
            if(a[i]==b[j]){
                r[j++]=i;
                c++;
            }
            else if(i+1<n && p[i+1]>=m-c-1){
                r[j++]=i++;
                while(j<m){
                    if(a[i]==b[j]) r[j++]=i;
                    i++;
                }
                return r;
            }
        }

        if(c==m) return r;
        return {};
    }
};
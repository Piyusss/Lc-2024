class Solution {
public:
    int smallestIndex(vector<int>& a) {
        int n=a.size(),x=0,s=0;

        for(int i=0;i<n;i++){
            x=a[i],s=0;
            
            while(x){
                s+=x%10;
                x/=10;
            }

            if(s==i) return i;
        }

        return -1;
    }
};
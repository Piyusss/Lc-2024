class Solution {
public:
    int pivotInteger(int n) {
        vector<int>v1,v2;
        for(int i=1;i<=n;i++){
            v1.push_back(i);
            v2.push_back(n-i+1);
        }
        for(int i=1;i<n;i++){
            v1[i]+=v1[i-1];
            v2[i]+=v2[i-1];
        }

        int cnt=1,i=0,j=n-1;
        while(i<n){
            if(v1[i]==v2[j])return cnt;
            cnt++;
            i++;
            j--;
        }
        return -1;
    }
};
// 9
// 1 2 3 4 5 6 7 8
// 1 3 6 10 15 21 28 36

// 8 7 6 5 4 3 2 1
// 8 15 21 26 30 33 35 36
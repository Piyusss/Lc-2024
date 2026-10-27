class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>a(m);
        
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) a[i].push_back(!i||j==n-1?'.':'#');
        return a;
    }
};
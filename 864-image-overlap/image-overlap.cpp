class Solution {
public:
    int f(int rowOff,int colOff,vector<vector<int>>A,vector<vector<int>>B,int n){
        int noOfOnes=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //here i and j are indexes of A
                int B_i=i+rowOff;
                int B_j=j+colOff;

                if(B_i<0 || B_j<0 || B_i>=n || B_j>=n)continue;
                if(A[i][j]==B[B_i][B_j] && A[i][j]==1)noOfOnes++;
            }
        }
        return noOfOnes;
    }
    int largestOverlap(vector<vector<int>>&A,vector<vector<int>>&B) {
        int n=A.size();
        int maxi=0;
        for(int rowOff=-n+1;rowOff<=n-1;rowOff++){
            for(int colOff=-n+1;colOff<=n-1;colOff++){
                maxi=max(maxi,f(rowOff,colOff,A,B,n));
            }
        }
        return maxi;
    }
};
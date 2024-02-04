class Solution {
public:
vector<int>generateRow(int row){
    long long ans=1;
    vector<int>ansRow;
    ansRow.push_back(1);
    for(int col=1;col<=row-1;col++){
        ans=ans*(row-col);
        ans=ans/(col);
        ansRow.push_back(ans);
    }
    return ansRow;
}
    vector<int> getRow(int rowIndex) {
        vector<int>ans=generateRow(rowIndex+1);
        return ans;
    }
};
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0,j=n-1;
        int maxi=0,score=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                maxi=max(maxi,score);
                i++;
            }
            else if(score>=1){
                score--;
                power+=tokens[j];
                j--;
            }
            else return maxi;
        }
        return maxi;
    }
};
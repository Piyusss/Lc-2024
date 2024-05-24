class Solution {
public:

int w;
int l;
int s;

map<char,int>mpS;
int maxScore=INT_MIN;


void f(int idx,vector<string>& words,vector<int>& score,int curScore,map<char,int>&mpL){
    maxScore=max(maxScore,curScore);
    if(idx>=w)return;

    //check if present word is completely present in mapL or not
    int j=0;
    int tempScore=0;
    map<char,int>freqMpL=mpL;
    while(j<words[idx].length()){
        if(mpL[words[idx][j]]<=0){
            mpL=freqMpL;
            break;
        }
        tempScore+=mpS[words[idx][j]];
        mpL[words[idx][j]]--;
        j++;
    }
    //pick- since its present after above check
    if(j==words[idx].length()){
        f(idx+1,words,score,curScore+tempScore,mpL);
    }

    //not-pick
    f(idx+1,words,score,curScore,freqMpL);

}
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score){
        map<char,int>mpL;
        w=words.size();
        char ch='a';
        for(auto it:letters)mpL[it]++;
        for(auto it:score){
            mpS[ch]=it;
            ch++;
        }
        f(0,words,score,0,mpL);
        return maxScore;
    }
};
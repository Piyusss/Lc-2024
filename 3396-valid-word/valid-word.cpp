class Solution {
public:

    bool isValid(string word) {
        int n=word.size();
        if(n<3) return 0;

        bool vCnt=0,cCnt=0;

        for(auto &c:word){
            if(!isalnum(c)) return 0;

            if(isalpha(c)){
                c=tolower(c);

                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') vCnt=1;
                else cCnt=1;
            }
        }

        return vCnt && cCnt;
    }
};
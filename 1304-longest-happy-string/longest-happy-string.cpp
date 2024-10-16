class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;

        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});

        string res="";

        while(!pq.empty()){
            auto curCharCnt=pq.top().first;
            auto curChar=pq.top().second;
            pq.pop();

            if(res.size()>=2 && curChar==res[res.size()-1] && curChar==res[res.size()-2]){
                if(pq.empty()) break;
                else{
                    auto smallCharCnt=pq.top().first;
                    auto smallChar=pq.top().second;
                    pq.pop();
                    res += smallChar;
                    smallCharCnt-=1;
                    if(smallCharCnt>0)pq.push({smallCharCnt,smallChar});
                }
            }
            else{
                res += curChar;
                curCharCnt-=1;
            }
            
            if(curCharCnt>0)pq.push({curCharCnt,curChar});
        }

        return res;

    }
};
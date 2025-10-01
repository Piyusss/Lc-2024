class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {        
        int cnt=numBottles;

        while(1){
            int empty=numBottles;
            int newBot = (empty/numExchange);
            int remEmpty=empty-(numExchange*(empty/numExchange));
            cnt += newBot;
            numBottles=newBot+remEmpty;
            if(numBottles < numExchange) break;
        }

        return cnt;
    }
};
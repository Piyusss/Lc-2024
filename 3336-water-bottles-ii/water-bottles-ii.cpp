class Solution {
public:
    int maxBottlesDrunk(int i, int j) {
        int tot=0,emp=0;
        while(i>0||emp>=j){
                tot+=i;
                emp+=i;
                i=0;
                if(emp>=j) {
                emp-=j;
                j++;i++;
            }
        }
        return tot;
    }
};
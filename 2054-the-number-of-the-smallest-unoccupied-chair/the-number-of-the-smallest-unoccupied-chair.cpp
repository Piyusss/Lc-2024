class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend){
        int n=times.size();
        int targetArrival=times[targetFriend][0];
        sort(times.begin(),times.end());

        vector<int>chairs(n,-1);

        for(auto &it:times){
            int arrival=it[0];
            int departure=it[1];

            for(int i=0;i<n;i++){
                if(chairs[i]<=arrival){
                    chairs[i]=departure;
                    if(arrival==targetArrival)return i;
                    break;
                }
            }
        }

        return -1;
    }
};
class Solution {
public:
    template<typename K, typename V>

    vector<pair<K, V>> sortMapByValue(map<K, V>& inputMap) {
    vector<pair<K, V>> sortedVec(inputMap.begin(), inputMap.end());
    sort(sortedVec.begin(), sortedVec.end(),
              [](pair<K, V>& a,pair<K, V>& b) {
                  return a.second < b.second;
              });

    return sortedVec;
}
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto it:arr)mp[it]++;
        auto sorted = sortMapByValue(mp);
        //now
        for (int i=0;i<sorted.size();) {
            if(k){sorted[i].second-=1;k--;if(sorted[i].second==0){i++;}}
            else{break;}
        }
        int cnt=0;
        for(auto it:sorted){
            if(it.second!=0)cnt++;
        }
        return cnt;
    }
};
// 4 3 3 3 2 1 1
// 1 1 2 3 3 4 5 8
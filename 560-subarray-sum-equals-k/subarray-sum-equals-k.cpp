class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
    int cnt=0;
    for(int i=0;i<v.size();i++){
        int sum=0;
		for(int j=i;j<v.size();j++){
			sum+=v[j];
            if(sum==k)cnt++;
		}
	}
    return cnt;
    }
};
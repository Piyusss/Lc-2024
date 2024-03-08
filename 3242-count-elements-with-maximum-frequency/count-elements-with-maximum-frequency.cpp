class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
    int maxFreq = 0, count = 0;

    for (int num : nums) {
        freq[num]++;
        if (freq[num] > maxFreq) {
            maxFreq = freq[num];
            count = freq[num];
        } else if (freq[num] == maxFreq) {
            count += freq[num];
        }
    }

    return count;
    }
};
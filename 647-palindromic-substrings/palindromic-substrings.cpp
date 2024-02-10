class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

    // Consider each character as a potential center and expand around it
    for (int i = 0; i < n; i++) {
        // Odd-length palindromes
        int left = i;
        int right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        // Even-length palindromes
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }
    return count;
    }
};
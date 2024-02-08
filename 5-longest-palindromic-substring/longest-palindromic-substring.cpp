class Solution {
public:
    string longestPalindrome(string s) {
         int n = s.length();
    int maxLength = 1;
    int start = 0;

    for (int i = 0; i < n; i++) {
        // Check for odd-length palindromes
        int left = i;
        int right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            int currentLength = right - left + 1;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = left;
            }
            left--;
            right++;
        }

        // Check for even-length palindromes
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            int currentLength = right - left + 1;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = left;
            }
            left--;
            right++;
        }
    }

    return s.substr(start, maxLength);
    }
};
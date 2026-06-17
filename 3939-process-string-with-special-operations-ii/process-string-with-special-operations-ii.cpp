class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        // Compute final length
        for (char c : s) {
            if (c == '*') {
                len = max(0LL, len - 1);
            } 
            else if (c == '#') {
                len *= 2;
            } 
            else if (c != '%') {
                len++;
            }
        }

        if (k >= len) return '.';

        // Work backwards
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (c == '*') {
                len++;
            }
            else if (c == '#') {
                len /= 2;
                if (k >= len) k -= len;
            }
            else if (c == '%') {
                k = len - 1 - k;
            }
            else { // lowercase letter
                len--;
                if (k == len) return c;
            }
        }

        return '.';
    }
};
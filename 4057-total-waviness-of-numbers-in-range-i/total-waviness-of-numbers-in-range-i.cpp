class Solution {
private:
    int waviness(int num) {
        string s = to_string(num);
        int n = s.size();

        if (n < 3) return 0;

        int count = 0;

        for (int i = 1; i < n - 1; i++) {
            char left = s[i - 1];
            char cur = s[i];
            char right = s[i + 1];

            if ((cur > left && cur > right) ||
                (cur < left && cur < right)) {
                count++;
            }
        }

        return count;
    }

public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int num = num1; num <= num2; num++) {
            ans += waviness(num);
        }

        return ans;
    }
};
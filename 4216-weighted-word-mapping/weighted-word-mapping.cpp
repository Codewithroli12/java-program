class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (string &word : words) {
            int sum = 0;

            for (char c : word) {
                sum = (sum + weights[c - 'a']) % 26;
            }

            // 0 -> 'z', 1 -> 'y', ..., 25 -> 'a'
            ans.push_back('a' + (25 - sum));
        }

        return ans;
    }
};
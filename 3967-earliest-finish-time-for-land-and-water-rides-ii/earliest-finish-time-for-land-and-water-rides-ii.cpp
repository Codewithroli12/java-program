class Solution {
private:
    int solve(vector<int>& start1, vector<int>& duration1,
              vector<int>& start2, vector<int>& duration2) {

        int earliestFinish = INT_MAX;

        for (int i = 0; i < start1.size(); i++) {
            earliestFinish = min(earliestFinish,
                                 start1[i] + duration1[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < start2.size(); i++) {
            ans = min(ans,
                      max(earliestFinish, start2[i]) + duration2[i]);
        }

        return ans;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        return min(
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration)
        );
    }
};
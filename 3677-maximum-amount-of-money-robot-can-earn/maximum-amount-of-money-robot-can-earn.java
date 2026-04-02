class Solution {
    int m, n;
    Integer[][][] dp;

    public int maximumAmount(int[][] coins) {
        m = coins.length;
        n = coins[0].length;
        dp = new Integer[m][n][3]; // skips = 0,1,2

        return helper(coins, 0, 0, 2);
    }

    int helper(int[][] coins, int i, int j, int skips) {
        // out of bounds
        if (i >= m || j >= n) return Integer.MIN_VALUE;

        if (dp[i][j][skips] != null) return dp[i][j][skips];

        // last cell
        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && skips > 0) return 0;
            return coins[i][j];
        }

        int right = helper(coins, i, j + 1, skips);
        int down = helper(coins, i + 1, j, skips);

        int best = Integer.MIN_VALUE;

        // normal move (avoid overflow)
        if (right != Integer.MIN_VALUE)
            best = Math.max(best, right + coins[i][j]);

        if (down != Integer.MIN_VALUE)
            best = Math.max(best, down + coins[i][j]);

        // skip negative cell
        if (coins[i][j] < 0 && skips > 0) {
            int rightSkip = helper(coins, i, j + 1, skips - 1);
            int downSkip = helper(coins, i + 1, j, skips - 1);

            best = Math.max(best, Math.max(rightSkip, downSkip));
        }

        return dp[i][j][skips] = best;
    }
}
class Solution {
public:
    int n;
    int dp[101][101];
    vector<int> suffix;

    int solve(int i, int M) {
        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        // Can take all remaining piles
        if (2 * M >= n - i)
            return dp[i][M] = suffix[i];

        int ans = 0;

        for (int X = 1; X <= 2 * M; X++) {
            // Current player takes X piles.
            // Opponent gets the best possible result from remaining piles.
            int opponent = solve(i + X, max(M, X));

            int current = suffix[i] - opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        memset(dp, -1, sizeof(dp));

        return solve(0, 1);
    }
};
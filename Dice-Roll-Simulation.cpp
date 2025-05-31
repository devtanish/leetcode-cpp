class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // The state of the dynamic programming (dp) table
        // dp[i][j][x] represents the number of sequences where:
        // i is the total rolls so far,
        // j is the last number rolled (1-6),
        // x is the consecutive times the last number j has been rolled.
        int dp[n][7][16];
        memset(dp, 0, sizeof dp); // Initialize the dp table with 0
        const int MOD = 1e9 + 7; // Define the modulo value

        // The recursive depth-first search function to explore the solution space
        std::function<int(int, int, int)> dfs = [&](int rollCount, int lastNumber, int consecCount) -> int {
            if (rollCount >= n) { // Base case: all dice have been rolled
                return 1;
            }
            if (dp[rollCount][lastNumber][consecCount]) { // Return memoized result
                return dp[rollCount][lastNumber][consecCount];
            }
            long long totalWays = 0; // Use long long to prevent overflow before taking mod
            for (int face = 1; face <= 6; ++face) {
                if (face != lastNumber) { // If the current face is different from the last number rolled
                    totalWays += dfs(rollCount + 1, face, 1); // Start count new number with 1
                } else if (consecCount < rollMax[lastNumber - 1]) { // If it's the same and under the rollMax limit
                    totalWays += dfs(rollCount + 1, lastNumber, consecCount + 1); // Continue sequence
                }
            }
            totalWays %= MOD; // Take modulo to prevent overflow
            return dp[rollCount][lastNumber][consecCount] = totalWays; // Memoize and return
        };

        // Invoke the dfs function starting with count 0, lastNumber 0 (dummy), and consecCount 0
        return dfs(0, 0, 0);
    }
};

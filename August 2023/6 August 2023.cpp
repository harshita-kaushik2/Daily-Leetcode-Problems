class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(n + 1, vector<long long>(goal + 1, -1));
        return calculateNumPlaylists(n, goal, k, dp) % 1000000007;
    }

    long long calculateNumPlaylists(int n, int goal, int k, vector<vector<long long>>& dp) {
        if (goal == 0 && n == 0) {
            return 1;
        }
        if (goal == 0 || n == 0) {
            return 0;
        }
        if (dp[n][goal] != -1) {
            return dp[n][goal];
        }

        long long replayCount = calculateNumPlaylists(n, goal - 1, k, dp) * max(n - k, 0);
        long long newSongCount = calculateNumPlaylists(n - 1, goal - 1, k, dp) * n;
        dp[n][goal] = (replayCount + newSongCount) % 1000000007;
        return dp[n][goal];
    }
};
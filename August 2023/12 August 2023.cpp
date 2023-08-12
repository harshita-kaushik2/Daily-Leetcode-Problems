/* Approach
If you have previously solved Unique Paths I the only change in this question is, the presence of obstacles. 
We have to find all paths except the paths that go via the obstacle cell. So for that, all we have to do is to add the condition :
if (obstacleGrid[i][j] == 1) dp[i][j] = 0;

Complexity
- Time complexity: O(n∗m)O(n * m)O(n∗m) because of the 2 for loops.
- Space complexity: O(n∗m)O(n*m)O(n∗m) because of the 2D vector. */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m,vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {                
                if (obstacleGrid[i][j] == 1)    dp[i][j] = 0;
                else if (i == 0 && j == 0)      dp[i][j] = 1;
                else {
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
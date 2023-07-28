/*Approach
Calculating the sum of player 2 by adding sum of all values of the array and them subtracting the score of player 1.
We want player 1 to win, so when it is the turn of player 1, maximize the score. When it is turn of player 2 minimize the score.
We do not take the total sum of player 2 in the solve() function.
Main Logic :
We need two pointers, one at the start of each array l and one at the end r

For the array : [15,100,2,10]

If player1 selects 15, array for player2 will be [100,2,10] which is l+1 to r
If player1 selects 10, array for player2 will be [15,100,2] which is l to r-1
We switch between turns of player1 to player2 using 1-turn */

// Recursion

class Solution {
public:     
    int solve(vector<int>& nums, int l, int r, int turn) {
        if (l > r) return 0;
        if (turn == 0)
            return max(nums[l] + solve(nums, l + 1, r, 1 - turn), nums[r] + solve(nums, l, r - 1, 1 - turn));
        else
           return min(solve(nums, l + 1, r, 1 - turn), solve(nums, l, r - 1, 1 - turn));
    }

    bool PredictTheWinner(vector<int>& nums) {
        int player1 = 0, player2 = 0;
        int left = 0, right = nums.size() - 1;

        for (int i : nums)
            player2 += i;

        player1 = solve(nums, left, right, 0);
        player2 -= player1;

        return player1 >= player2;
    }
};

// Memoization

class Solution {
public:     
    int dp[21][21][2];
    int solve(vector<int>& nums, int l, int r, int turn) {
        if (l > r) return 0;
        if (dp[l][r][turn] != -1)   return dp[l][r][turn];
        if (turn == 0)
            return dp[l][r][turn] = max(nums[l] + solve(nums, l + 1, r, 1 - turn), nums[r] + solve(nums, l, r - 1, 1 - turn));
        else
           return dp[l][r][turn] = min(solve(nums, l + 1, r, 1 - turn), solve(nums, l, r - 1, 1 - turn));
    }

    bool PredictTheWinner(vector<int>& nums) {
        int player1 = 0, player2 = 0;
        int left = 0, right = nums.size() - 1;
        memset(dp,-1,sizeof(dp));

        for (int i : nums)
            player2 += i;

        player1 = solve(nums, left, right, 0);
        player2 -= player1;

        return player1 >= player2;
    }
};
/*The given code solves the problem of finding the minimum sum of ASCII values of characters to be deleted from two strings, 
s1 and s2, such that the remaining strings become equal. 

The solution is achieved using dynamic programming with memoization. 

- We define a `calculate` function to compute the ASCII sum of a string, and a `solve `function to find the longest common subsequence (LCS) of the two strings. 

- In the main function `minimumDeleteSum` initializes a 2D DP array for memoization, calls the `solve` function to find the LCS,
calculates the total ASCII sum of both strings, subtracts twice the value of LCS from the total, and returns the minimum delete sum. */

class Solution {
public:
    int calculate(string s){
        int total = 0;
        for (auto i : s){
            total += (i - 'a') + 97;
        }
        return total;
    }
    
    int dp[1001][1001];
    
    int solve(string& s1, string& s2, int i, int j){
        if (i >= s1.size() or j >= s2.size()) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s1[i] == s2[j]) return dp[i][j] = (s1[i] - 'a') + 97 + solve(s1, s2, i+1, j+1);
        
        return dp[i][j] = max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
    }
    
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        int value = solve(s1, s2, 0, 0);
        int total = calculate(s2) + calculate(s1);
        total -= (2 * value);
        return total;
    }
};

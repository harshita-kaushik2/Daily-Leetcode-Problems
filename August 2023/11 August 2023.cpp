/*Approach
The approach uses a dynamic programming table dp, where dp[i] represents the number of combinations that can be formed to make the amount i.
The base case is dp[0] = 1, indicating that there is one way to make an amount of zero (by using no coins).

The nested loops iterate through each coin denomination in coins, and for each coin, it iterates through amounts from 1 to amount.
For each amount i, the condition if (i - c >= 0) checks if subtracting the coin value c doesn't result in a negative amount. 
If this condition is satisfied, it means we can consider using the coin c to make the amount i, and the number of combinations is updated using dp[i] += dp[i - c]. 
This step accumulates the number of combinations by considering both the current coin and the previously calculated combinations for the remaining amount.

Once both loops complete, the dp[amount] value holds the total number of combinations to make the given amount using the provided coin denominations. 
The function returns this value as the final answer

Complexity
- Time complexity: O(n∗amount)
- Space complexity: O(amount) */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0]=1;
        for(int c:coins){
            for(int i=1; i<=amount; i++)
                if (i-c>=0) dp[i]+=dp[i-c];
        }
        return dp[amount]; 
    }
};
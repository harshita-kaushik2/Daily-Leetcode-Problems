/*Intuition
The key idea behind this solution is to explore the possible valid partitions in the given array nums using a recursive approach.
At each step, we examine the current element and determine whether it fits the criteria to be part of a valid partition. 
We employ memoization to reduce unnecessary recalculations.

Approach
We design a recursive function named checkPartition(i, nums, dp) that takes the current index i, the array nums, and a memoization array dp as parameters.

During each recursive call, we evaluate the potential subarrays starting from index i and assess whether they satisfy the given conditions.

We consider three primary cases:
a. If the next two elements are equal to the element at nums[i], a valid subarray of length 3 with identical elements is formed.
b. If the next element is equal to nums[i], a valid subarray of length 2 with identical elements is formed.
c. If the next two elements are consecutive and increasing, a valid subarray of length 3 with consecutive increasing elements is formed.

The memoization technique is employed to store whether a particular index i leads to a valid partition. 
This reduces redundant computations and significantly enhances the efficiency of the algorithm. */

class Solution {
public: 
    bool solve(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        
        if (i >= n) return true; 
        
        if (dp[i] != -1) return dp[i];
        
        if (i + 1 < n) {
            if (nums[i + 1] == nums[i]) {
                if (i + 2 < n) {
                    if (nums[i + 2] == nums[i]) {
                        return dp[i] = solve(i + 2, nums, dp) || solve(i + 3, nums, dp);
                    }
                    return dp[i] = solve(i + 2, nums, dp);
                }
                return dp[i] = true;
            }
            
            if (nums[i + 1] == nums[i] + 1) {
                if (i + 2 >= n) return dp[i] = false;
                if (nums[i + 2] == nums[i] + 2) 
                    return dp[i] = solve(i + 3, nums, dp);
                
                return dp[i] = false;
            }
            return dp[i] = false;
        }
        return dp[i] =  false;
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};
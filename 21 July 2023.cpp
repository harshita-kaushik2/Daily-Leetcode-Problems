/*Try this question for better understanding of Longest Increasing Subsequence :
https://leetcode.com/problems/longest-increasing-subsequence/description/

Approach
- Initialize n, the number of elements in nums, and handle the edge case where n is 0 by returning 0.
- Declare ans and maxi to keep track of the number of longest increasing subsequences and the length of the longest subsequence found so far, respectively.
- Create two arrays dp and count, both of size n, to store the length of the longest increasing subsequence ending at each index and the count of such subsequences.
- Iterate through each element in nums.
- For each element nums[i], iterate through all elements before it (indices [0, i)).
- Compare nums[i] and nums[j], where j is the index being iterated in the inner loop.
- If nums[i] is greater than nums[j] and the length of the increasing subsequence ending at index i (dp[i]) is less than 1 + dp[j], update dp[i] and count[i] accordingly,
finding a new longer increasing subsequence ending at i.
- If nums[i] is greater than nums[j] and dp[i] is equal to 1 + dp[j], it means we found another subsequence with the same length, so increment count[i] by the value of count[j].
- Update maxi to keep track of the maximum length of increasing subsequences seen so far.
codeFinally, loop through the dp array again, and for each index i, if dp[i] is equal to maxi, increment ans by count[i]. The final ans will represent the total number of
longest increasing subsequences in nums, which is returned as the result.*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return 0;
        int ans = 0;
        int maxi=1;
        vector<int>dp(n,1), count(n,1);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                } 
                else if (nums[i] > nums[j] && dp[i] == 1 + dp[j])   
                    count[i] += count[j];   
            }
            maxi = max(maxi,dp[i]);
        }

        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi)   ans += count[i];
        }
        return ans;
    }
};
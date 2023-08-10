/*Only thing that makes this problem different from Search in Rotated Sorted Array I is the presence of duplicate elements.

Consider a scenario such as : nums = [3, 2, 1, 3, 3, 3, 3]
Here nums[mid] = 3, nums[low] = 3, nums[high] = 3. Thus we are unable to indentify the sorted half, and hence cannot perform the search.

So, in order to eliminate this case, if we come across :
(nums[mid] == nums[low] && nums[mid] == nums[high]) = We shorten our search space to the next element from low by low++ and previous element from high by high--.
And we continue doing this until we find numbers that are unequal. On them we can perform the operation of checking for the sorted half like we did in Search in Rotated Sorted Array I */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while(low <= high) {
            int mid = (high + low)/2;
            if(nums[mid] == target) return true;
            if(nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            if(nums[low] <= nums[mid]) {
                if(nums[low] <= target && target <= nums[mid] ) {
                    high = mid - 1;
                }
                else      low = mid + 1;
            }
            else {
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else    high = mid - 1;  
            }
        }
        return false;
    }
};
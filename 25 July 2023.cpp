/*Intuition
As soon as you read that constraints that mention that the problem has to be solved in O(log n) time, jump to Binary Search directly.

Approach
A mountain array increases first and then decreases. The peak element is the element that is strictly greater than its neighbors.
We can use binary search to efficiently find the peak element by comparing the middle element with its adjacent element.
If the middle element is smaller than its right neighbor, then the peak element must be on the right side of the middle element,
so we update the left pointer to mid + 1.
Otherwise, if the middle element is greater than or equal to its right neighbor, then the peak element must be 
on the left side of the middle element, so we update the right pointer to mid.
Complexity
- Time complexity: O ( log n )
- Space complexity: O( 1 )*/


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int left = 0;
       int right = arr.size()-1;

       while(left < right){
           int mid = (left + (right-left)/2);
           if(arr[mid] < arr[mid+1])
           left = mid+1;
           else
           right = mid;
       }
       return left;
    }
};
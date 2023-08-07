/*Approach
The given solution uses a binary search approach to find the target element in the 2D matrix.

The matrix is considered as a 1D sorted array, and the binary search is performed on it. The algorithm first calculates the number of 
rows (row) and columns (col) in the matrix. Then, it sets low to 0 and high to the last index of the 1D representation of the matrix, which is (row * col) - 1.

The while loop continues until the low index is less than or equal to the high index. In each iteration, it calculates the middle index (mid) 
using (low + high) / 2 to divide the search range in half. The element at matrix[mid/col][mid%col] is checked against the target. 
If they are equal, the function returns true as the target element is found.

If the element at the middle index is less than the target, it means the target lies in the right half of the search range. 
The low index is updated to mid + 1 to narrow down the search to the right half.

Otherwise, if the element at the middle index is greater than the target, it means the target lies in the left half of the search range. 
The high index is updated to mid - 1 to narrow down the search to the left half.

If the while loop finishes without finding the target element, it means the element is not present in the matrix, and the function returns false.

Complexity
Time complexity: O(log (row * col))
Space complexity: O(1) */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = (row*col)-1;

        while(low<=high){
            int mid = high+(low-high)/2;
            if(matrix[mid/col][mid%col]==target)
            return true;

            else if(matrix[mid/col][mid%col]<target)
            low = mid+1;
            else
            high = mid-1;
        }
        return false;
    }
};
/*Intuition
It is pretty clear from the question that, when the starting of next interval is smaller than the ending of the current interval, we have an overlap.

To move to the next checks, we have to remove one of the 2 overlapping intervals. The question is, which one ?

In case of overlapping subinterval :
We want the interval that has smaller ending value, and remove the interval with larger ending value. Reason for doing this is because a smaller 
ending value would avoid overlaps with the upcoming intervals.
Thus in case of overlap of [1,2] and [1,3] we remove [1,3] which has larger ending value.

Approach
Sort the intervals on basis of starting value.
Compare the ending of current interval end_curr with the starting of the next interval next_start
Overlap exists if next_start < end_curr. In that case :
Increase the count of subinterval to be removed because one of them has to be removed.
Retain the interval that has smaller ending value that is done using curr_end = min(curr_end, next_end)
If overlap does not exist, simply move to the next interval by making curr_end = next_end
Return count.
Complexity
Time complexity: O(n logn) because of the sorting.
Space complexity: O(1)*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int curr_end = intervals[0][1];
        int count = 0;

        for(int i = 1; i<intervals.size(); i++){
            int next_start = intervals[i][0];
            int next_end = intervals[i][1];
            if(next_start < curr_end ) {
                count++;
                curr_end = min(curr_end, next_end);
            }
            else    curr_end = next_end;
        }
        return count;
    }
};
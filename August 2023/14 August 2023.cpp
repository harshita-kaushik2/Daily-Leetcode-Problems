/*# Approach 1 : Sorting the Array
Since you need Kth largest element, sort the vector in decreasing order as sort(nums.begin(), nums.end(), greater<int>());
Return the Kth largest element which will then be at the indexK-1of the vector.

Complexity
- Time complexity: O(nlogn)
- Space complexity: O(1) */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};

/*# Approach 2 : Using Min Heap
How to identify that this question can be solved using Heap?
99% on questions in Heap will use the the words : "K" and "smallest/largest/closest".
So, whenever you see a question involving these words, always run your mind to Heaps.

Why use Min Heap ?
As a thumb rule :
- When asked for smallest element, use Max Heap.
- When asked for largest element, use Min Heap.

Working Approach
In a min heap, the root node always contains the smallest element in the heap.
Whenever the size of the heap increases more than k, pop-out the top most element. 
This will make sure all the elements which are small are popped out and out min-heap will contain elements starting from the kth largest element.

1. Build Min Heap: Initially, you build a min heap of the first K elements from the array. 
This can be done in linear time, O(K), by repeatedly inserting elements into the heap.

2. Iterate Through the Remaining Elements: Starting from the (K+1)th element in the array, iterate through the rest of the elements. 
For each element:
- Compare the element with the root of the min heap (the smallest element among the K largest found so far).
- If the current element is larger than the root of the min heap, replace the root with the current element and perform the necessary heap operations to restore the min heap properties.

Result: Once you have iterated through the entire array, the root of the min heap will contain the Kth largest element. 
This is because the smallest element among the K largest elements will be at the root of the min heap.

Complexity
- Time complexity: O(nlogk)
- Space complexity: O(k) */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i< nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
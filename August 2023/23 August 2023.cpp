Approach
To be able to make striong with non-adjacent elemtns we have to count the frequency of the elements and then place the most frequent elements first, for example in case of "aab" frequency of a = 2, b = 1. So we first place a->b->a to make a non-adjacent string.

But the approach of just putting the most frequent element first does not work. For example, for frequency a = 3, b = 1, c = 1, if we put most frequent element first followed by each of other element, we will end up with "abcaa" which gives us the wrong answer.

Instead of that we just have to put a hold on the previous element that we just used. We can select the next most frequent element excpet prev. Doing that for frequency a = 3, b = 1, c = 1, we will end up with "abaca"

Why Priority Queue ?
We're also going to have to keep track of which a previous value we use so that we don't reuse the same value two times in a row. But the time complexity doing that with a hash map scanning through it each time is going to be roughly n^2 in the worst case. So instead, to find the most frequent, we can use heap. In this case, since we want most frequent element, we use a MaxHeap since it stores the maximum count. And thus we can do this in O(logn)O(logn)O(logn) complexity.

Complexity
Time complexity: O(k∗logn)O(k*logn)O(k∗logn)

Space complexity: O(n)O(n)O(n)

Code
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> chrCounts(26);
        for (auto& chr : s)     chrCounts[chr - 'a']++;
    
        priority_queue<pair<int, char>> max_heap;
        for (int i = 0; i < 26; i++) {
            if (chrCounts[i] > 0) {
                max_heap.push({chrCounts[i], 'a' + i});
            }
        }

        string result = "";
        pair<int, char> prev = max_heap.top();
        max_heap.pop();
        result += prev.second;
        while (!max_heap.empty()) {
            pair<int, char> curr = max_heap.top();
            max_heap.pop();
            result += curr.second;
            if (--prev.first > 0) max_heap.push(prev);
            prev = curr;
        }

        if (result.size() != s.size())   return "";
        return result;
    }
};
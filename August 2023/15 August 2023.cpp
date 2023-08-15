Approach
We maintain two separate linked lists: one for nodes with values less than x, and another for nodes with values greater than or equal to x.

The logic iterates through the input linked list, examining each node's value. If the node's value is less than x, it is appended to the "smaller" list. If the value is greater than or equal to x, it is appended to the "larger" list. During this process, the code keeps track of the current nodes in both the "smaller" and "larger" lists.

After processing all nodes, if the "smaller" list is empty, the function returns the "larger" list, effectively preserving the original order of nodes greater than or equal to x. Otherwise, it connects the tail of the "smaller" list to the head of the "larger" list and returns the head of the "smaller" list, effectively forming a partition where nodes less than x appear before nodes greater than or equal to x.


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
       ListNode* smallerHead = nullptr;
       ListNode* smallerCurr = nullptr;
       ListNode* largerHead = nullptr;
       ListNode* largerCurr = nullptr; 
       ListNode* curr = head;

        while(curr)
        {
            if(curr->val < x)
            {
                if(smallerHead == nullptr)
                {
                    smallerHead = curr;
                    smallerCurr = curr;
                }
                else
                {
                    smallerCurr->next = curr;
                    smallerCurr = smallerCurr->next;
                }
                curr = curr->next;
                smallerCurr->next = nullptr;
            }
            else
            {
                if(largerHead == nullptr)
                {
                    largerHead = curr;
                    largerCurr = curr;
                }
                else
                {
                    largerCurr->next = curr;
                    largerCurr = largerCurr->next;
                }
                curr = curr->next;
                largerCurr->next = nullptr;
            }
        }
        
        if(!smallerCurr)    return largerHead;
        
        smallerCurr->next = largerHead;
        return smallerHead;
    }
};
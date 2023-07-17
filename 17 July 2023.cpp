/*Approach 1 : By Reversing both the lists
This approach reverses the input lists, performs the addition digit by digit, handles the carry, and then reverses the result back to the original order.

Step-by-Step
Reverse both input linked lists l1 and l2 using reverseList function.
Create a new linked list ans and initialize it with a dummy node.
Set up a pointer curr to point to ans.
Initialize a variable carry to 0.
Iterate while either l1, l2, or carry has a value:
Initialize a variable sum to 0.
If l1 is not NULL, add its value to sum and move l1 to the next node.
If l2 is not NULL, add its value to sum and move l2 to the next node.
Add the current carry value to sum.
Update carry by dividing sum by 10.
Create a new node with the value sum % 10 and assign it to node.
Set curr->next to node and move curr to the next node.
After the loop, check if there's any remaining carry. If so, create a new node with the value of carry and append it to the result.
Reverse the ans linked list (excluding the dummy node) using the reverseList function.
Return the reversed ans linked list.*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry > 0) {
            int sum = 0;
            
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum % 10);
            curr -> next = node;
            curr = curr ->next;
        }
        ans = reverseList(ans->next);
        return ans;
    }
};
/*Approach 2 : Without Reversing the lists
The idea is to count the number of nodes in each linked list, determine the bigger and smaller lists, perform addition digit by digit, 
handle any carry, and return the resulting linked list representing the sum.

Step-by-Step
Calculate the lengths of the two linked lists list1 and list2 using the getNodeCount function.
Initialize a variable carry to store the carry value during addition.
Determine the bigger and smaller linked lists based on their lengths.
Add the digits of the smaller linked list to the corresponding digits of the bigger linked list using the addEqualLengthLists function. 
Update the carry value as necessary.
If the bigger linked list has more digits, continue adding the remaining digits with the carry using the addLinkedLists function. 
Update the carry value as necessary.
If there is a remaining carry after adding all the digits, create a new node with the carry value and append it to the bigger linked list.
Return the modified bigger linked list, which now represents the sum of the two input linked lists.*/


class Solution {
public:
    void getNodeCount(ListNode* head, int& count) {
        if (head == NULL) return;
        count++;
        getNodeCount(head->next, count);
    }

    void addEqualLengthLists(ListNode* &list1, ListNode* list2, int& carry) {
        if (list1 == NULL) return;
        if (list1->next)
            addEqualLengthLists(list1->next, list2->next, carry);
        int sum = list1->val + list2->val + carry;
        list1->val = (sum) % 10;
        carry = (sum) / 10;
    }

    void addLinkedLists(ListNode* &bigList, ListNode* smallList, int count1, int count2, int& carry) {
        if (bigList == NULL) return;
        if (count1 <= count2) {
            addEqualLengthLists(bigList, smallList, carry);
            return;
        }
        else {
            addLinkedLists(bigList->next, smallList, count1 - 1, count2, carry);
        }
        if (carry > 0) {
            int sum = bigList->val + carry;
            bigList->val = (sum) % 10;
            carry = (sum) / 10;
        }
    }

    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        int count1 = 0, count2 = 0;
        getNodeCount(list1, count1);
        getNodeCount(list2, count2);
        int carry = 0;
        ListNode* bigList;
        ListNode* smallList;
        if (count1 >= count2) {
            bigList = list1;
            smallList = list2;
        } else {
            bigList = list2;
            smallList = list1;
        }
        addLinkedLists(bigList, smallList, (count1 >= count2) ? count1 : count2, (count2 <= count1) ? count2 : count1, carry);
        if (carry > 0) {
            ListNode* tmp = new ListNode(carry);
            tmp->next = bigList;
            bigList = tmp;
        }
        return bigList;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* forward = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forward;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL) return NULL;

        // Step 1: Reverse the list
        ListNode* reversedHead = reverse(head);

        // Step 2: Delete the nth node from the start of the reversed list
        if (n == 1) { // Special case: deleting the first node in the reversed list
            ListNode* toDelete = reversedHead;
            reversedHead = reversedHead->next;
            delete toDelete;
        } else {
            ListNode* temp = reversedHead;
            int count = 1;
            while (temp->next != NULL && count < n - 1) {
                temp = temp->next;
                count++;
            }

            // Delete the nth node
            ListNode* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }

        // Step 3: Reverse the list back to its original order
        return reverse(reversedHead);
    }
};

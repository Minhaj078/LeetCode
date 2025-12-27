/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* cycle(ListNode* head){
        if(head == NULL || head ->next == NULL)return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)return slow;
        }
        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)return NULL;

        ListNode * intersection = cycle(head);

        ListNode * slow = head;

        if(intersection == NULL)return NULL;

        while(slow != intersection){
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }
};
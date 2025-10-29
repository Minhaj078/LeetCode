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
    int getlen(ListNode* head)
    {
        int len = 0;
        while(head != NULL)
        {
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode* middleNode(ListNode* head) {
        int x = 0;
        int len = getlen(head);
        while(x != len/2){
            head = head->next;
            x++;
        }
        return head;
    }
};
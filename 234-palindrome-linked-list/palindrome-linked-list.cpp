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

    int getlen(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    }

    bool isPalindrome(ListNode* head) {
        int len = getlen(head);
        int arr[len];
        int i = 0;
        ListNode* temp = head;


        while(temp != NULL){
            arr[i] = temp->val;
            temp = temp->next;
            i++;
        }
        int left = 0, right = len-1;
        
        while(left < right){
            if(arr[left] != arr[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
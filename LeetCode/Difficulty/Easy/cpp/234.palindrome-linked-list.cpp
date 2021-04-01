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
    
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* getListMid(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        ListNode *mid = getListMid(head);
        ListNode *revHead = reverseList(mid->next);
        mid->next = NULL;
        
        ListNode *l1 = head, *l2 = revHead;
        while (l2) {
            if (l1->val != l2->val) return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        mid->next = reverseList(revHead);
        return true;
    }
};
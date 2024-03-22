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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        // Find the middle of the linked list
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the first half of the linked list
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != slow) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Handle odd-length linked list
        if (fast)
            slow = slow->next;

        // Compare the two halves of the linked list
        while (prev && slow) {
            if (prev->val != slow->val)
                return false;
            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};
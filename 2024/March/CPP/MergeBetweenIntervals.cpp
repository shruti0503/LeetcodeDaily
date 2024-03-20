#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *curr = list1;
        
        // Traverse to the node at position (a - 1)
        for (int i = 0; i < a - 1; ++i) {
            curr = curr->next;
        }
        
        ListNode *temp = curr->next;  // Store the node at position a
        curr->next = list2;  // Attach list2 to list1 at position a
        
        // Traverse to the end of list2
        while (list2->next != nullptr) {
            list2 = list2->next;
        }
        
        // Traverse to the node at position (b + 1)
        for (int i = a; i < b + 1; ++i) {
            temp = temp->next;
        }
        
        // Attach the remaining part of list1 after position b to list2
        list2->next = temp;
        
        return list1;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example 1
    ListNode* list1 = new ListNode(10);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(13);
    list1->next->next->next = new ListNode(6);
    list1->next->next->next->next = new ListNode(9);
    list1->next->next->next->next->next = new ListNode(5);
    
    ListNode* list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);
    
    Solution sol;
    ListNode* result = sol.mergeInBetween(list1, 3, 4, list2);
    cout << "Example 1 Output: ";
    printList(result);
    
    // Example 2
    ListNode* list3 = new ListNode(0);
    list3->next = new ListNode(1);
    list3->next->next = new ListNode(2);
    list3->next->next->next = new ListNode(3);
    list3->next->next->next->next = new ListNode(4);
    list3->next->next->next->next->next = new ListNode(5);
    list3->next->next->next->next->next->next = new ListNode(6);
    
    ListNode* list4 = new ListNode(1000000);
    list4->next = new ListNode(1000001);
    list4->next->next = new ListNode(1000002);
    list4->next->next->next = new ListNode(1000003);
    list4->next->next->next->next = new ListNode(1000004);
    
    ListNode* result2 = sol.mergeInBetween(list3, 2, 5, list4);
    cout << "Example 2 Output: ";
    printList(result2);
    
    return 0;
}

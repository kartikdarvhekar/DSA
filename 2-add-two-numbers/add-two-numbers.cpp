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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to act as the starting point of our new list
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        
        // This will keep track of any carry-over (e.g., 8 + 5 = 13, carry = 1)
        int carry = 0;
        
        // Loop continues as long as there are nodes left in either list, or a carry remains
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;
            
            // If l1 has a node, add its value and move to the next node
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // If l2 has a node, add its value and move to the next node
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Calculate the new carry for the next iteration (e.g., 13 / 10 = 1)
            carry = sum / 10;
            
            // Create a new node with the ones-digit of the sum (e.g., 13 % 10 = 3)
            current->next = new ListNode(sum % 10);
            
            // Move our pointer forward
            current = current->next;
        }
        
        // The real result starts right after our placeholder dummy node
        ListNode* result = dummyHead->next;
        delete dummyHead; // Free the memory of the dummy node to avoid leaks
        
        return result;
    }
};
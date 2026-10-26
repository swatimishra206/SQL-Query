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

        // Dummy node: result list banane ke liye
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        int carry = 0;  // Extra carry store karega

        // Jab tak dono lists ya carry bacha hai
        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int sum = carry;

            // First list ka digit add karo
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Second list ka digit add karo
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Current digit aur next carry nikalo
            carry = sum / 10;
            int digit = sum % 10;

            // Result mein new node add karo
            current->next = new ListNode(digit);
            current = current->next;
        }

        // Dummy node ko chhodkar result return karo
        return dummy->next;
    }
};
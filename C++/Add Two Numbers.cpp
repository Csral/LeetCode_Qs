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
        
        ListNode ans;
        ListNode* calc = &ans;

        int s_carry = 0;

        while (l1 || l2 || s_carry) {
            
            s_carry = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + s_carry;

            calc->next = new ListNode(s_carry % 10);
            calc = calc->next;

            s_carry = s_carry / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

        }

        return ans.next;

    }
};

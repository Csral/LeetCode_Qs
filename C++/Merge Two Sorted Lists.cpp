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
#include <vector>
#include <algorithm>
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        std::vector<int> vec;
        ListNode* t = list1;
        
        while (t != nullptr) {
            vec.push_back(t->val);
            t = t->next;
        }

        t = list2;

        while (t != nullptr) {
            vec.push_back(t->val);
            t = t->next;
        }

        std::sort(vec.begin(), vec.end());
        size_t v_size = vec.size();

        if (v_size == 0)
            return nullptr;

        ListNode* head;
        t = new ListNode;
        t->val = vec.at(0);
        head = t;
        
        for (size_t i = 1; i < v_size; i++) {
            t->next = new ListNode;
            t->next->val = vec.at(i);
            t = t->next;
        }

        return head;

    }
};

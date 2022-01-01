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
        int tmp = 0;
        ListNode *res = new ListNode;
        ListNode *head = res;
        while((l1 || l2) || tmp > 0)
        {
            if(l1) {
                tmp += l1->val;
                l1 = l1->next;
            }
                
            if(l2) {
                tmp += l2->val;
                l2 = l2->next;
            }
            ListNode *node = new ListNode;
            res -> next = node;
            node->val = tmp % 10;
            tmp /= 10;
            res = res->next;
        }
        return head->next;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode((l1->val + l2->val) % 10);
        ListNode *p = head;
        int cnt = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL){
                ListNode *p1 = new ListNode(0);
                p1->val = (l2->val + cnt) % 10;
                cnt = (l2->val + cnt) / 10;
                l2 = l2->next;
                p->next = p1;
                p = p->next;
            }
            else if(l2 == NULL){
                ListNode *p1 = new ListNode(0);
                p1->val = (l1->val + cnt) % 10;
                cnt = (l1->val + cnt) / 10;
                l1 = l1->next;
                p->next = p1;
                p = p->next;
            }
            else{
                ListNode *p1 = new ListNode(0);
                p1->val = (l1->val + l2->val + cnt) % 10;
                cnt = (l1->val + l2->val + cnt) / 10;
                l1 = l1->next;
                l2 = l2->next;
                p->next = p1;
                p = p->next;
            }
        }
        if(cnt > 0){
                ListNode *p1 = new ListNode(0);
                p1->val = cnt;
                p->next = p1;
                p = p->next;
        }
        return head;
    }
};

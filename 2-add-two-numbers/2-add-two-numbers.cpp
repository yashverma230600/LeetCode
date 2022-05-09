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
        int carry = 0;
        int sum = 0;
        ListNode * h = new ListNode(-1);
        ListNode * res = h;
        while(l1&&l2)
        {
            sum = (l1->val + l2->val) + carry;
            carry = sum/10;
            sum = sum % 10;
            h->next= new ListNode(sum);
            h=h->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            sum = (l1->val) + carry;
            carry = sum/10;
            sum = sum % 10;
            h->next= new ListNode(sum);
            h=h->next;
            l1=l1->next;
        }
        while(l2)
        {
            sum = (l2->val) + carry  ;
            carry = sum/10;
            sum = sum % 10;
            h->next= new ListNode(sum);
            h=h->next;
            l2=l2->next;
        }
        if(carry) 
        {
            h->next = new ListNode(carry);
        }
        return res->next;
    }
};
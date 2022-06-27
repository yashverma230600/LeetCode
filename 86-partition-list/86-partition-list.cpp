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
    ListNode* partition(ListNode* head, int x) {
        if(!head){
            return NULL;
        }
        ListNode* dummy_f=new ListNode();
        ListNode* dummy_s=new ListNode();
        ListNode* first = dummy_f;
        ListNode* second = dummy_s;
        
        while(head!=NULL){
            if(head->val<x){
                dummy_f->next=head;
                dummy_f=head;
            }
            else{
                dummy_s->next=head;
                dummy_s=head;
            }
            head=head->next;
        }
        dummy_s->next=NULL;
        dummy_f->next=second->next;
        
        
        return first->next;
        
        
    }
};
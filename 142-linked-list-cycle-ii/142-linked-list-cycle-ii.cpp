
class Solution {
public: // preRequisite is Flod Algorithm
    
    ListNode *start_loop(ListNode *p,ListNode *q)
    {
        while(p && q)
        {
            if(p==q)
                return p;
            
            p=p->next;
            q=q->next;
        }
        
        return nullptr;
    }
    
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *p=head,*q=head;
        
        while( p && q && q->next )
        {
            p= p->next;
            q= q->next->next;
            
            if(p==q)
            {
                p= start_loop(p,head);
                return p;
            }
        }
        
        return nullptr;
        
    }
};
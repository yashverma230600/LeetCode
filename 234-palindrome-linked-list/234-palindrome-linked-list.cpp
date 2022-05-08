class Solution {
public:
bool isPalindrome(ListNode* head) {

    stack <int> st;
    ListNode* dummy = new ListNode(0,head);
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    while(slow){
        st.push(slow->val);
        slow = slow->next;
    }
    
    while(!st.empty()){
        
        if(st.top()!=head->val) return false;
        head = head->next;
        st.pop();
    }
    return true;
}
};
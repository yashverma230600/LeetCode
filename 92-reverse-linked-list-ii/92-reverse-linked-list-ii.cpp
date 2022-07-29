class Solution {
public:
    ListNode* find(ListNode*root ,int n)
    {
        if(n<1)
        {
            return NULL;
        }
        for(int i=1;i<n;i++)
        {
            if(!root)
            {
                return NULL;
            }
            root=root->next;
        }
        return root;
    }
    ListNode* rev(ListNode* root,int n)
    {
        if(n==1)
        {
            return root;
        }
        ListNode* temp3=rev(root->next,n-1);
        temp3->next=root;
        return root;
    }
        
    ListNode* reverseBetween(ListNode* root, int left, int right) {
        if(!root->next)
        {
            return root;
        }
        ListNode* lft=find(root,left),*rgt=find(root,right);
        ListNode* temp1,*temp2;
        
        temp1=find(root,left-1);
        
        temp2=find(root,right+1);
        
        rev(lft,right-left+1);
        if(temp1)
        {
            temp1->next=rgt;
        }
        else
        {
            root=rgt;
        }
        
            lft->next=temp2;
			
        return root;
        
        
    }
};
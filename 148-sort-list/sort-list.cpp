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
    ListNode* findmiddle(ListNode* head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
}

ListNode* merge(ListNode* left,ListNode*right){
    if(left == NULL) return right;
if(right == NULL) return left;
    ListNode* mergehead=NULL;

   if(left->val<right->val){ mergehead=left; 
   left=left->next;
   }

   else {mergehead=right;
   right=right->next;}
   ListNode*temp=mergehead;
   while(left!=NULL&&right!=NULL){
    if(left->val<right->val){
        temp->next=left;
        left=left->next;
       
    }
else{
    temp->next=right;
    right=right->next;

}
temp=temp->next;
   }
   while(left!=NULL){
    temp->next=left;
    left=left->next;
    temp=temp->next;

   }
    while(right!=NULL){
    temp->next=right;
    right=right->next;
    temp=temp->next;
   }
   return mergehead;
}
    ListNode* sortList(ListNode* head) {
      if(head==NULL||head->next==NULL) return head;
      ListNode*mid= findmiddle(head);
      ListNode*right=mid->next;
      mid->next=NULL;
      ListNode*left=head;
      left=sortList(left);
      right=sortList(right);
      return merge(left,right);
    }
};
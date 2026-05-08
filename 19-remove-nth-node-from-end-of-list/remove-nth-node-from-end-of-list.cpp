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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=1;
        ListNode*temp=head;
        if(head->next==NULL&&n==1) return NULL;
        if(head->next->next==NULL&&n==1) {
            head->next=NULL;
            return head;
        }  
           if(head->next->next==NULL&&n==2) {
            head=head->next;
            return head;
        }  
        while(temp->next!=NULL){
            temp=temp->next;
            cnt++;
        }
        int k=cnt-n+1;
        int i=1;
        ListNode*temp1=head;
        if(k==1){
            head=head->next;
            return head;
        }
        while(i!=k-1&&temp1!=NULL){
          temp1=temp1->next;
          i++;
        
        }
        temp1->next=temp1->next->next;
        return head;
    }
};
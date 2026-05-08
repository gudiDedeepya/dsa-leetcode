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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* heada=headA;
         ListNode* headb=headB;


      while(heada != headb) {

    heada = (heada == NULL) ? headB : heada->next;

    headb = (headb == NULL) ? headA : headb->next;
}
        if(heada==headb) return heada;
        return NULL;
    }
};
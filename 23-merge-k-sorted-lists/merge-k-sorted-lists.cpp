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
struct comparator{
   bool operator()(ListNode*a,ListNode* b){
        return a->val>b->val;
   }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comparator>min_heap;

        for(ListNode* head:lists){
            if(head!=NULL)
            min_heap.push(head);
            
        }
        ListNode*dummy=new ListNode(0);
        ListNode*tail=dummy;
        while(!min_heap.empty()){
            ListNode* node=min_heap.top();
            min_heap.pop();
            tail->next=node;
            tail=tail->next;
            if(node->next!=NULL)
            min_heap.push(node->next);

        }
       return dummy->next;
    }
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (true) {

            // Find kth node
            ListNode* kth = prev;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == NULL)
                    return dummy->next;
            }

            // Save the beginning of next group
            ListNode* groupNext = kth->next;

            // Reverse current group
            ListNode* curr = prev->next;
            ListNode* before = groupNext;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = before;
                before = curr;
                curr = temp;
            }

            // Connect previous part to reversed group
            ListNode* oldStart = prev->next;

            prev->next = kth;

            // oldStart is now the tail
            prev = oldStart;
        }
    }
};
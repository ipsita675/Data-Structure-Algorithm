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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* curr=head;

        while(curr){
            ListNode* temp=curr->next;

            ListNode* posn=dummy;
            while(posn->next && posn->next->val<curr->val)posn=posn->next;

            curr->next=posn->next;
            posn->next=curr;

            curr=temp;
        }

        return dummy->next;
    }
};
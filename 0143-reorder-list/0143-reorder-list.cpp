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
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* temp=slow->next;
        slow->next=NULL;

        ListNode* curr=temp;
        ListNode* prev=NULL;

        while(curr){
            ListNode* node=curr->next;
            curr->next=prev;
            prev=curr;
            curr=node;
        }

        temp=prev;
        curr=head;

        while(temp){
            ListNode* node1=curr->next;
            ListNode* node2=temp->next;

            curr->next=temp;
            temp->next=node1;

            curr=node1;
            temp=node2;
        }

        
    }
};
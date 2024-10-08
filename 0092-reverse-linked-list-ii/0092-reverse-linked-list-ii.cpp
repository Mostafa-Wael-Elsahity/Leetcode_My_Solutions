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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *prev=dummy;
        ListNode *cur=head;
        ListNode *n=head;
        for(int i=0;i<left-1;i++){
            prev=prev->next;
        }
        cur=prev->next;
        n=cur->next;
        for(int i=0;i<right-left;i++){
            ListNode* temp = prev -> next;
           prev -> next = cur -> next;
           cur -> next = cur -> next -> next;
           prev -> next -> next = temp;
        }
        return dummy->next;
    }
};
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        ListNode* d1 = small;
        ListNode* d2 = large;
        ListNode* current = head;
        while(current){
            if(current->val < x){
                small->next = current;
                small = small->next;
            }
            else{
                large->next = current;
                large = large->next;
            }
            current = current->next;
        }
        large->next = nullptr;
        small->next = d2->next;
        return d1->next;
    }
};
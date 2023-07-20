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
        vector<ListNode*>v;
        int ctr=-1;
        left--,right--;
        while(head){
            v.push_back(head);
            head=head->next,ctr++;
        }
        while(left<right) swap(v[left++],v[right--]);
        for(int i=0;i<ctr;i++) v[i]->next=v[i+1];
        v[ctr]->next=NULL;
        return head=v[0];
    }
};
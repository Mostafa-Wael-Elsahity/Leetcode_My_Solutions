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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        stack<ListNode*>f,s;
        while(l1){
            f.push(l1);
            l1=l1->next;
        }
        while(l2){
            s.push(l2);
            l2=l2->next;
        }
        int remain=0;
        while(!f.empty()||!s.empty()||remain){
            int a=remain;
            if(!f.empty()){
                a+=f.top()->val;
                f.pop();
            }
            if(!s.empty()){
                a+=s.top()->val;
                s.pop();
            }
            remain=a/10;
            ListNode* node=new ListNode(a%10);
            node->next=head;
            head=node;
        }
        return head;
    }
};
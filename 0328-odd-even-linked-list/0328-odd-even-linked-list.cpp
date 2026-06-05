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
    
    ListNode* oddEvenList(ListNode* head) {
        if(!head|| !head->next) return head;

        ListNode*t1=head;
        ListNode*newHead=head->next;
        ListNode*t2=newHead;

        while(t2 && t2->next){
            t1->next=t2->next;
            
            t2->next=t2->next->next;

            t1=t1->next;
            t2=t2->next;
        }
        t1->next=newHead;

        return head;

    }
};
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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode *temp=head->next;
        ListNode*prev=head;
        head->next=NULL;
        while(temp){
            ListNode* next_tra_node=temp->next;
            temp->next=prev;
            prev=temp;
                    head=temp;

            temp=next_tra_node;

        }



        return head;
    }
};
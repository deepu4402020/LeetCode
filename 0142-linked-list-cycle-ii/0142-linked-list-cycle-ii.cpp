/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        map<ListNode*, int> visited;

        ListNode* temp = head;

        while(temp != NULL){

            if(visited[temp])
                return temp;

            visited[temp] = 1;

            temp = temp->next;
        }

        return temp;
    }
};
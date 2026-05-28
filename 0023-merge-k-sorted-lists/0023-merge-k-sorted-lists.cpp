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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

        for (auto i : lists) {

            ListNode* temp = i;

            while (temp) {
                pq.push(temp);
                temp = temp->next;
            }
        }

        if (pq.empty())
            return NULL;

        ListNode* head = pq.top();
        ListNode* temp = head;

        pq.pop();

        while (!pq.empty()) {
            temp->next = pq.top();
            pq.pop();

            temp = temp->next;
        }

        temp->next = NULL;

        return head;
    }
};
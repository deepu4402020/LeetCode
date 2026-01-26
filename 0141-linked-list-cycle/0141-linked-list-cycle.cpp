
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(!head) return false;
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast && slow && fast != slow) {
            if(!fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast == slow)
            return true;
        return false;
    }
};
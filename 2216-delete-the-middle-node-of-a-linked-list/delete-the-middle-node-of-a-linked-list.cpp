class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;

        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* ptr = head;
        while (ptr->next != slow) {
            ptr = ptr->next;
        }

        ptr->next = slow->next;
        return head;
    }
};
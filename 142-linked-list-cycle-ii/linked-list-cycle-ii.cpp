class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> vis;

        while (head) {
            if (vis.count(head))
                return head;

            vis.insert(head);
            head = head->next;
        }

        return nullptr;
    }
};

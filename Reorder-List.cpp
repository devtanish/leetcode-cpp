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
    void reorderList(ListNode* head) {
        if (!head || !(head->next) || !(head->next->next)) {
            // If the list has 0, 1, or 2 nodes, no reordering is needed.
            return;
        }

        // Use the fast and slow pointer technique to find the middle of the list.
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next; // Move one step.
            fast = fast->next->next; // Move two steps.
        }

        // Split the list into two halves.
        ListNode* secondHalf = slow->next;
        slow->next = nullptr; // Terminate first half.

        // Reverse the second half of the list.
        ListNode* prev = nullptr;
        while (secondHalf) {
            ListNode* temp = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = temp;
        }

        // Start merging the first and second halves one node at a time.
        ListNode* firstHalf = head;
        ListNode* secondHalfHead = prev; // Points to the head of the reversed second half.
        while (secondHalfHead) {
            ListNode* temp = secondHalfHead->next;
            secondHalfHead->next = firstHalf->next;
            firstHalf->next = secondHalfHead;

            // Move pointers ahead.
            firstHalf = secondHalfHead->next; // Moved to the next of the newly added node.
            secondHalfHead = temp; // Moving to the next node in the reversed half.
        }
    }
};

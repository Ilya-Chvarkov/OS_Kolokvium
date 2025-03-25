#include "LinkedList.h"

ListNode* LinkedList::ReverseRecursive(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* newHead = ReverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

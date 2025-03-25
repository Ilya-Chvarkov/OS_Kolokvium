#include "LinkedList.h"
#include <gtest/gtest.h>

TEST(LinkedListTest, HandlesEmptyList) {
    EXPECT_EQ(LinkedList::ReverseRecursive(nullptr), nullptr);
}

TEST(LinkedListTest, ReversesList) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode* reversed = LinkedList::ReverseRecursive(head);

    EXPECT_EQ(reversed->val, 3);
    EXPECT_EQ(reversed->next->val, 2);
    EXPECT_EQ(reversed->next->next->val, 1);
    EXPECT_EQ(reversed->next->next->next, nullptr);
}

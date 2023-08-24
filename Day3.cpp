#include <iostream>

class ListNode {
public:
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

ListNode* find_middle(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* merge(ListNode* left, ListNode* right) {
    if (!left)
        return right;
    if (!right)
        return left;

    ListNode* merged = nullptr;
    if (left->value < right->value) {
        merged = left;
        merged->next = merge(left->next, right);
    } else {
        merged = right;
        merged->next = merge(left, right->next);
    }

    return merged;
}

ListNode* merge_sort(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* mid = find_middle(head);
    ListNode* midNext = mid->next;
    mid->next = nullptr;

    ListNode* left = merge_sort(head);
    ListNode* right = merge_sort(midNext);

    return merge(left, right);
}

void print_linked_list(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(34);

    std::cout << "Original Linked List: ";
    print_linked_list(head);

    ListNode* sorted_head = merge_sort(head);
    std::cout << "Sorted Linked List: ";
    print_linked_list(sorted_head);

    // Clean up memory
    while (sorted_head) {
        ListNode* temp = sorted_head;
        sorted_head = sorted_head->next;
        delete temp;
    }

    return 0;
}

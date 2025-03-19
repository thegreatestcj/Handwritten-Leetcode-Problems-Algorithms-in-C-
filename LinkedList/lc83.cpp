#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
    ListNode(int val, ListNode* nextptr): val(val), next(nextptr) {}
};

void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* removeDuplicatesFromSortedList(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    ListNode* start = head;
    ListNode* end = head;

    while (start && start->next) {
        end = start->next;
        while (end && end->val == start->val)
        {
            start->next = end->next;
            end = start->next;
        }
        start = end;
    }

    return head;
}

void test() {
    // [1, 1, 2, 3, 4, 5, 5, 5, 6, 6]
    // With duplicates at the front, end, and in the middle.
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next->next->next->next = new ListNode(6);

    ListNode* newHead = removeDuplicatesFromSortedList(head);
    cout << "After deleting the duplicates: " << endl;
    printList(newHead);
}


int main() {
    test();
    return 0;
}
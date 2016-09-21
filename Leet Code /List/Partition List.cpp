#include <iostream>

using namespace std;

typedef struct ListNode {
	int value;
	ListNode *next;
}ListNode;
ListNode *Partition(ListNode *head, int x) {
	ListNode *left = new ListNode();
	ListNode *right = new ListNode();
	
	ListNode *left_p = left;
	ListNode *right_p = right;
	for (ListNode *cur = head;cur; cur = cur->next) {
		if (cur->value < x) {
			left_p->next = cur;
			left_p = cur;
		} else {
			right_p->next = cur;
			right_p = cur;
		}
	}
	left_p->next = right->next;
	right_p->next = nullptr;
	
	return left->next;
}
int main(int argc, char *argv[]) {
	
}
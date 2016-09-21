#include <iostream>

using namespace std;
typedef struct ListNode {
	int value;
	ListNode *next;
}ListNode;

void recur(ListNode *prev, ListNode *cur) {
	if (cur == nullptr) {
		return;
	}
	if (prev->value == cur->value) {
		prev->next = cur->next;
		delete cur;
		recur(prev, prev->next);
	} else {
		recur(prev->value, cur->next);
	}
}
ListNode *deleteDuplicates(ListNode *head) {
	ListNode *pre = head;
	while (pre->next != nullptr) {
		ListNode *next = pre->next;
		if (pre->value == next->value)) {
			ListNode *deleNext = next->next;
			pre->next = dele;
			delete next;
		}
		pre = pre->next;
	}
	
}
int main(int argc, char *argv[]) {
	
}
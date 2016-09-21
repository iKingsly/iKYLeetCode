#include <iostream>

using namespace std;
typedef struct ListNode {
	int value;
	ListNode *next;
}ListNode;
ListNode *deleteDuplicates(ListNode *head) {
	if (head == nullptr) {
		return head;
	}
	
	ListNode * dummy = new ListNode ();
	dummy->next = head;
	ListNode *prev = dummy, *cur = head;
	while (cur != nullptr) {
		bool duplicated = false;
		while (cur->next != nullptr && cur->value == cur->next->value) {
			duplicated = true_type;
			ListNode *temp = cur;
			cur = cur->next;
			delete temp;
		}
		if (duplicated) {
			ListNode *temp = cur;
			cur = cur->next;
			delete temp;
			continue;
		}
		prev->next = cur;
		prev = prev->next;
		cur = cur->next;
	}
	prev->next = cur;
	return dummy->next;
}
int main(int argc, char *argv[]) {
	
}
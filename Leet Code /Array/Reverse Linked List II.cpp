#include <iostream>

using namespace std;
typedef struct ListNode {
	int value;
	ListNode *next;
}ListNode;
ListNode reverseList(ListNode *head, int m, int n) {
	ListNode *dummy = new ListNode (0);
	ListNode *prev = dummy;
	for (int i = 0;i < m - 1;i ++) {
		prev = prev->next;
	}
	ListNode * const head2 = prev;
	prev = head2->next;
	ListNode *cur = prev->next;
	for (int i = m;i < n;i++) {
		prev->next = cur->next;
		cur->next = head2->next;
		head2->next = cur;
		cur = prev->next;
	}
	return dummy->next;
}
int main(int argc, char *argv[]) {
	
}
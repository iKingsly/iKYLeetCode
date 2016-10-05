#include <iostream>

using namespace std;
typedef struct ListNode {
	int value;
	ListNode *next;
}ListNode;
ListNode *swapNodesInPairs(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode *newHead = head->next;
	
	for (ListNode *prev = newHead, *cur = prev->next, *next = cur->next;next;prev = cur, cur = cur->next, next = cur ? cur->next : NULL) {
		prev->next = next;
		cur->next = next->next;
		next->next = cur;
	}
}
int main(int argc, char *argv[]) {
	
}
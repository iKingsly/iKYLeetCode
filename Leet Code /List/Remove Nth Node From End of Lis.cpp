#include <iostream>

using namespace std;
typedef struct ListNode {
	int value;
	ListNode *next;
}ListNode;
ListNode *removeNthFromEnd (ListNode *head, unsigned int n) {
	ListNode *pre = NULL, *next = NULL;
	pre = next = head;
	for ( int i = 0 ;i < n; i++) {
		if (pre->next) {
			pre = pre->next;
		} else {
			// throw an error 
			return NULL;
		}
	}
	while (pre->next) {
		pre = pre->next;
		next = next->next;
	}
	
	ListNode *temp = next->next;
	next->next = temp->next;
	delete temp;
	return head;
}
int main(int argc, char *argv[]) {
	
}
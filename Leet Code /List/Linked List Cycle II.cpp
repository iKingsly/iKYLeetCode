#include <iostream>

using namespace std;
typedef struct ListNode {
	int value;
	ListNode *next;
}ListNode;

ListNode *detectCycle (ListNode *head) {
	
	ListNode *fast = head, *slow = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			slow = head;
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return nullptr;
}
int main(int argc, char *argv[]) {
	
}
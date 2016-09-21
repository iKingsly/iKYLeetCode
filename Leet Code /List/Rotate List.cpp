#include <iostream>

using namespace std;
typedef struct ListNode {
	int value;
	ListNode *next;
}ListNode;
ListNode *rorateList(ListNode *head, int k) {
	if (head == nullptr || k == 0) return head;
	
	int length = 1;
	ListNode *pre = head;
	while (pre->next) {
		pre = pre->next;
		length++;
	}
	int j = length - j % length;
	
	pre->next = head;
	for (int step = 0;step < k; step++) {
		pre = pre->next;
	}
	head = pre->next;
	pre->next = nullptr;
	return head;
	
}
int main(int argc, char *argv[]) {
	
}
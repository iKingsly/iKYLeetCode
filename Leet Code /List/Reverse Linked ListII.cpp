#include <iostream>

using namespace std;
typedef struct ListNode {
	int value;
	ListNode *next;
}ListNode;
ListNode reversePart (ListNode *head, int from , int to) {
	int len = 0;
	ListNode *node1 = head;
	ListNode *fPre = null;
	ListNode *fPos = null;
	while (node1 != null) {
		len++;
		fPre = len == from - 1 ? node1 : fPre;
		fPos = len == to + 1 ? node1 : fPos;
		node1 = node1->next;
	}
	
	if (from > to || from < 1 || to > len) {
		return head;
	}
	node1 = fPre == null ? head: fPre->next;
	ListNode *node2 = node1->next;
	ListNode *next = null;
	while (node2 != fPos) {
		next = node2->next;
		node2->next = node1;
		node1 = node2;
		node2 = next;
	}
	
	if (fPre != null) {
		fPre->next = node1;
		return head;
	}
	return node1;
}
int main(int argc, char *argv[]) {
	
}
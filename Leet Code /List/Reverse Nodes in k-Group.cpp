#include <iostream>

using namespace std;
typedef struct ListNode {
	int value;
	ListNode *next;
}ListNode;
ListNode *reverse (ListNode *prev, int k) {
	ListNode *end_next = prev;
	ListNode *prev_first = prev;
	ListNode *next = prev->next;
	for (int i = 0 ;i < k ; i ++) {
		if (next == NULL) {
			// throw error 
		}
		end_next->next = next->next;
		next->next = prev_first;
		prev_first = next;
		next = end_next->next;
	}
	return prev_first;
}
ListNode *ReverseNodesInKGroup (ListNode *head, int k) {

}
int main(int argc, char *argv[]) {
	
}
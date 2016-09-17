#include <iostream>
using namespace std;
typedef struct ListNode {
	int value;
	ListNode *next;
}ListNode;

ListNode *addTwoNumbers (ListNode *l1, ListNode *l2) {
	ListNode *dummy = nullptr;
	int carry = 0;
	ListNode *prev = dummy;
	for (ListNode *pa = l1, *pb = l2;pa != nullptr || pb!= nullptr;pa = pa == nullptr ? : 0: *pa->next,pb = pb == nullptr ? : 0: *pb->next, prev = *prev->next) {
		const int ai = pa == nullptr ? 0 : pa->value;
		const int bi = pb == nullptr ? 0 : pb->value;
		const int value = (ai + bi + carry) % 10;
		carry = (ai + bi + carry) / 10;
		prev->next = new  ListNode(value);
	}
	if (carry > 0) {
		prev->next = new ListNode (carry);
	}
	return dummy;
}

int main(int argc, char *argv[]) {
	
}
/* Program: Swap pairs in Linked list
 * Weblink: https://leetcode.com/explore/learn/card/recursion-i/250/principle-of-recursion/1681/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
using namespace std;

struct ListNode
{
	int data;
	ListNode *next;
};

void printList(ListNode *l)
{
	while (l != nullptr) {
		std::cout << l->data << " -> ";
		l = l->next;
	}
	std::cout << "NULL" << std::endl;
}

ListNode* reverse(ListNode *head, ListNode *prev)
{
	if (head == nullptr) return nullptr;
	if (head->next == nullptr) {
		head->next = prev;
		return head;
	}
	ListNode *next = head->next;
	head->next = prev;
	return reverse(next, head);
}

ListNode* swapPairs(ListNode* head)
{
	if (head == nullptr || head->next == nullptr) return head;
	ListNode *next = head->next;
	head->next = swapPairs(next->next);
	next->next = head;
	return next;
}

int main() {
	ListNode *head;
	head = new ListNode;
	head->data = 10;
	head->next = new ListNode;
	head->next->data = 20;
	head->next->next = new ListNode;
	head->next->next->data = 30;
	head->next->next->next = new ListNode;
	head->next->next->next->data = 40;
	head->next->next->next->next = new ListNode;
	head->next->next->next->next->data = 50;
	head->next->next->next->next->next = nullptr;

	printList(head);
	head = reverse(head, nullptr);
	printList(head);
	head = swapPairs(head);
	printList(head);

	return 0;
}

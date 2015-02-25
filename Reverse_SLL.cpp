#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *link;
	ListNode(int x) : val(x), link(NULL) {}
};

ListNode* reverse(ListNode* root)
{
	ListNode* current = root;
	ListNode* previous = NULL;
	ListNode* next;

	while(current != NULL)
	{
		next = previous;
		previous = current;
		current = current->link;
		previous->link = next;
	}

	root = previous;
	return root;
}

int main()
{	
	ListNode* newNode1 = new ListNode(1);
	ListNode* newNode2 = new ListNode(2);
	ListNode* newNode3 = new ListNode(3);
	newNode1->link = newNode2;
	newNode2->link = newNode3;

	ListNode* temp = newNode1;

	while(temp != NULL)
	{
		cout<<temp->val<<endl;
		temp = temp->link;
	}

	ListNode* result = reverse(newNode1);

	while(result != NULL)
	{
		cout<<result->val<<endl;
		result = result->link;
	}
}
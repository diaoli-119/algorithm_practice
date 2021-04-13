#include <iostream>
#include <string>
#include <vector>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


using std::cout;
using std::cin;
using std::endl;

bool palindromeLinkedList(ListNode *head)
{
	if (!head->next) return false;
	std::vector<int> v;
	ListNode *p,*q;
	p = head->next;
	q = head->next;
	
	while (q->next)
	{
		v.push_back(p->val);
		p = q->next;
		q = p;
	}
	int n = v.size() / 2;
	int m = v.size();
	for (int i = 0; i < n; i++)
	{
		if (v[i] == v[m - i - 1])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}
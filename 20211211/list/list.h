#include <iostream>
#include <vector>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x)
		: val(x)
		, next(NULL)
	{
	}
};

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x)
		: lcable(x)
		, next(NULL)
		, random(NULL) {
		  }
};
class mod_list
{
private:


public:
	vector<int> printListFromTailToHead_1(List *head);
	vector<int> printListFromTailToHead_2(List *head);
	ListNode *ReverseList(ListNode *pHead);
	ListNode *Merge(ListNode *pHead1, ListNode *pHead2);
	ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2);
	ListNode *EntryNodeOfLoop(ListNode *pHead);
	ListNode *FindKthToTail(ListNode *pHead, int k);
	RandomListNode *clone(RandomListNode *pHead);
	ListNode *delteDuplication(ListNode *pHead);
	ListNode *deleteNode(ListNode *head, int val);
};

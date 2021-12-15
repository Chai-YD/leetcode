#include "list.h"

vector<int> mod_list::printListFromTailToHead_1(ListNode *head)
{
	vector<int> vec;
	stack<int> sta;
	ListNode *cur = NULL;
	if (!head) {
		return vec;
	}

	cur = head;
	while (cur != NULL) {
		sta.push(cur->val);
		cur = cur->next;
	}

	while (!sta.empty()) {
		vec.push_back(sta.top());
		sta.pop();	
	}

	return vec;
}

vector<int> mod_list::printListFromTailToHead_2(ListNode *head)
{
	/* 反转链表 */
	vector<int> vec;
	ListNode *prev = NULL;
	ListNode *cur = NULL;
	if (!head) {
		return vec;
	}

	cur = head;
	while (cur != NULL) {
		ListNode *tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}

	cur = prev;
	while (cur != NULL) {
		vec.push_back(cur->val);
		cur = cur->next;
	}

	return vec;
}

ListNode* mod_list::ReverseList(ListNode *pHead)
{
	if (!pHead) {
		return pHead;
	}

	ListNode *prev = NULL;
	ListNode *cur = NULL;

	cur = pHead;
	while (NULL != cur) {
		ListNode *tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	pHead = prev;

	return pHead;
}

ListNode *mode_list::Merge(ListNode *pHead1, ListNode *pHead2)
{
	if (!pHead1) {
		return pHead2;
	}
	if (!pHead2) {
		return pHead1;
	}

	ListNode *rHead = NULL;
	ListNode *cur3 = NULL;
	ListNode *cur1 = pHead1;
	ListNode *cur2 = pHead2;

	if (cur1->val > cur2->val) {
		cur3 = cur2;
		cur2 = cur2->next;
	}
	else {
		cur3 = cur1;
		cur1 = cur1->next;
	}
	rHead = cur3;
	while (cur1 && cur2) {
		int flag = 1;
		if (cur1->val < cur2->val) {
			flag = 0;
		}
		if (flag == 0) {
			cur3->next = cur1;
			cur1 = cur1->next;
		}	
		else {
			cur3->next = cur2;
			cur2 = cur2->next;
		}
		cur3 = cur3->next;
	}

	if (!cur1) {
		cur3->next = cur2;
	}
	else {
		cur3->next = cur1;
	}

	return rHead;
}

ListNode *mod_list::FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
	int len1 = 0;
	int len2 = 0;

	if (!pHead1 || !pHead2) {
		return NULL;
	}

	ListNode *cur1 = pHead1;
	ListNode *cur2 = pHead2;

	while (cur1) {
		len1++;
		cur1 = cur1->next;
	}
	while (cur2) {
		len2++;
		cur2 = cur2->next;
	}

	int flag = 0;
	int num = 0;

	if (len1 > len2) {
		flag = 1;	
		num = len1 - len2;
	}
	else {
		num = len2 - len1;
	}

	cur1 = pHead1;
	cur2 = pHead2;
	while (num--) {
		if (flag == 1) {
			cur1 = cur1->next;
		}
		else {
			cur2 = cur2->next;	
		}
	}
	while (cur1 && cur2) {
		if (cur1 == cur2) {
			return cur1;
		}
		else {
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}

	return NULL;
}

ListNode *mod_list::EntryNodeOfLoop(ListNode *pHead)
{
	if (!pHead) {
		return NULL;
	}
	ListNode *fast = pHead;
	ListNode *slow = pHead;

	while (fast &&fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) {
			fast = pHead;
			while (fast != slow) {
				fast = fast->next;
				slow = slow->next;
			}
			if (fast == slow) {
				return fast;
			}
		}
	}

	return NULL;
}

ListNode *mod_list::FindKthToTail(ListNode *pHead, int k)
{
	if (!pHead || k < 1) {
		return NULL;
	}
	int num = 0;
	ListNode *cur = pHead;
	while (cur) {
		num++;
		cur = cur->next;
	}

	if (num < k) {
		return NULL;
	}

	ListNode *slow = pHead;
	cur = pHead;
	while (k--) {
		cur = cur->next;
	}
	while (cur) {
		slow = slow->next;
		cur = cur->next;
	}

	return slow;
}

RandomListNode *mod_list::clone(RandomListNode *pHead)
{
	if (!pHead) {
		return NULL;
	}

	RandomListNode *cur = pHead;
	while (cur) {
		RandomListNode *tmp = new RandomListNode(cur->label);
		tmp->next = cur->next;
		cur->next = tmp;
		cur = tmp->next;
	}

	cur = pHead;
	RandomListNode *p = NULL;
	while (cur) {
		p = cur->next;
		if (cur->random != NULL) {
			p->random = cur->random->next;
		}
		else {
			p->random = NULL;
		}
		cur = p->next;
	}

	cur = pHead;
	RandomListNode *head = pHead->next;
	RandomListNode *tmp;
	while (cur->next) {
		tmp = cur->next;
		cur->next = tmp->next;
		cur = tmp;
	}

	return head;
}

ListNode *mod_list::delteDuplication(ListNode *pHead)
{
	if (!pHead) {
		return NULL;
	}

	ListNode *head = NULL;
	ListNode *tmp = NULL;
	ListNode *prev = NULL;
	ListNode *cur = pHead;

	while (cur) {
		if (cur->next && cur->val != cur->next->val) {
			if (!tmp || tmp->val != cur->val) {
				if (!head) {
					head = cur;
				}
				if (!prev) {
					prev = cur;
				}
				else {
					prev->next = cur;
					prev = cur;
				}
			}
		}
		else if (!cur->next) {
			if (!tmp || tmp->val != cur->val) {
				if (!head) {
					head = cur;
				}
				if (!prev) {
					prev = cur;
				}
				else {
					prev->next = cur;
					prev = cur;
				}
			}
			else {
				if (prev) {
					prev->next = NULL;
				}
			}
		}
		else {
			tmp = cur;
		}
		cur = cur->next;
	}

	return head;
}

ListNode *mod_list::deleteNode(ListNode *head, int val)
{
	if (!head) {
		return head;
	}

	ListNode *cur = head;
	ListNode *prev = NULL;
	while (cur) {
		if (cur->val == val) {
			if (cur == head) {
				head = cur->next;
			}
			if (prev) {
				prev->next = cur->next;
			}
		}
		else {
			prev = cur;
		}
		cur = cur->next;
	}

	return head;
}

#include <iostream>
#include <vector>

#include "coutData.h"

using namespace std;

//��Ŀ����
//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
//���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
//����˼·
//���ⴴ���������飬���������ż����Ȼ�����ԭʼ���飬����д��
void reOrderArray(vector<int> &array) 
{
	vector<int> odd;
	vector<int> even;
	vector<int>::iterator ite;
	for (ite = array.begin(); ite != array.end(); ++ite)
	{
		if ((*ite) % 2 == 0)
			even.push_back(*ite);
		else
			odd.push_back(*ite);
	}
	coutData(odd);
	coutData(even);
	array.clear();
	array.insert(array.end(), odd.begin(), odd.end());
	array.insert(array.end(), even.begin(), even.end());
}

//��Ŀ����
//����һ����������������е�����k����㡣
//�ⷨһ�����α���
//�ⷨ����������ָ�룬��һ��ָ������k����㣬Ȼ������ָ��ͬʱ�ߣ�ֱ����������������
struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
//�ⷨ��
	if (k <= 0 || pListHead == NULL)
		return NULL;
	ListNode* pf = pListHead;
	ListNode* pb = pListHead;
	for (int i = 0; i != k; ++i)
	{
		if (pf != NULL)
			pf = pf->next;
		else
			return NULL;
	}
	while (pf != NULL)
	{
		pf = pf->next;
		pb = pb->next;
	}
	return pb;
//�ⷨһ
	//int length = 0;
	//ListNode* current = pListHead;
	//int n = 0;
	//if (pListHead == NULL || k <= 0)
	//	return NULL;
	//while (current != NULL)
	//{
	//	current = current->next;
	//	++length;
	//}
	//if (k > length)
	//	return NULL;
	//n = length - k;
	//current = pListHead;
	//while (current != NULL && n > 0)
	//{
	//	current = current->next;
	//	--n;
	//}
	//return current;
}
//
//��Ŀ����
//����һ��������ת��������������ı�ͷ��
//����˼·
//��Ҫ�����ĸ���ʱ������ǰһ�����pre����һ�����pnext����ǰ���current���������ͷrev
//1.�����ж��Ƿ��ǿ�����
//2.��ʼ��pre��pnext��revΪNULL��currentΪpHEAD.
//3.pext = current->next;
//  current->next = prev;
//  pre = current;
//  current = pnext;
ListNode* ReverseList(ListNode* pHead) 
{
	if (pHead == NULL)
		return NULL;
	ListNode* pre = NULL;
	ListNode* pnext = NULL;
	ListNode* current = pHead;
	ListNode* rev = NULL;
	while (current != NULL)
	{
		pnext = current->next;
		if (pnext == NULL)
			rev = current;
		current->next = pre;
		pre = current;
		current = pnext;
	}
	return rev;
}

//���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL && pHead2 != NULL)
		return pHead2;
	else if (pHead1 != NULL && pHead2 == NULL)
		return pHead1;
	else if (pHead1 == NULL && pHead2 == NULL)
		return NULL;
	ListNode* ans = pHead1->val > pHead2->val ? pHead1 : pHead2;
	ListNode* baseCurrent = ans;
	ListNode* temp = NULL;
	int baseVal, comVal;
	ListNode* comCurrent = NULL;
	if (ans == pHead1)
		comCurrent = pHead2;
	else if (ans == pHead2)
		comCurrent = pHead1;
	while (comCurrent != NULL)
	{
		comVal = comCurrent->val;
		baseVal = baseCurrent->val;
		while (baseVal < comVal && baseCurrent->next != NULL)
		{
			baseCurrent = baseCurrent->next;
			baseVal = baseCurrent->val;
		}
		temp = baseCurrent;
		baseCurrent->next = comCurrent;
		baseCurrent->next->next = temp->next;
		baseCurrent = temp->next;
		comCurrent = comCurrent->next;
	}
	return ans;
}

int main()
{
	/*vector<int> array;
	array = { 1, 2, 3, 4, 5, 6, 7 };
	reOrderArray(array);
	coutData(array);*/
	ListNode p(0);
	p.val = 0;
	p.next = NULL;
	//cout << p.val;
	ListNode* p1 = &p;
	ListNode *p1t = &p;
	for (int i = 1; i < 5; ++i)
	{
		p1t->next = new ListNode(i);
		p1t = p1t->next;
	}
	while (p1 != NULL)
	{
		cout << p1->val << " ";
		p1 = p1->next;
	}
	cout << endl;
	return 0;
}
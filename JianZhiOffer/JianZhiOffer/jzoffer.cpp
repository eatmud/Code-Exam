#include <iostream>
#include <vector>

#include "coutData.h"

using namespace std;

//题目描述
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
//所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
//解题思路
//另外创建两个数组，存放奇数与偶数，然后清空原始数组，重新写入
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

//题目描述
//输入一个链表，输出该链表中倒数第k个结点。
//解法一：两次遍历
//解法二：用两个指针，第一个指针先走k个结点，然后两个指针同时走，直到遍历完整个链表
struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
//解法二
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
//解法一
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
//题目描述
//输入一个链表，反转链表后，输出新链表的表头。
//解题思路
//需要定义四个临时变量，前一个结点pre，下一个结点pnext，当前结点current，新链表表头rev
//1.首先判断是否是空链表
//2.初始化pre、pnext、rev为NULL，current为pHEAD.
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

//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
//解法一：递归实现
//
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL )
		    return pHead2;
	    if (pHead2 == NULL)
		    return pHead1;
        if (pHead1->val <= pHead2->val)
        {
            pHead1->next = Merge(pHead1->next,pHead2);
            return pHead1;
        }
        else
        {
            pHead2->next = Merge(pHead1,pHead2->next);
            return pHead2;
        }
}
/*非递归解法
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL )
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	ListNode* merge = NULL;
	ListNode* current = NULL;
	if (pHead1->val <= pHead2->val)
	{
		current = pHead1;
		pHead1 = pHead1->next;
	}
	else
	{
		current = pHead2;
		pHead2 = pHead2->next;
	}
	merge = current;
	while(pHead1 != NULL || pHead2 != NULL)
	{
		if(pHead1 == NULL)
		{
			current->next = pHead2;
			current = current->next;
			pHead2 = pHead2->next;
			continue;
		}
		if(pHead2 == NULL)
		{
			current->next = pHead1;
			current = current->next;
			pHead1  = pHead1->next;
			continue;
		}
		if (pHead1->val <= pHead2->val)
		{
			current->next = pHead1;
			current = current->next;
			pHead1 = pHead1->next;
		}
		else
		{
			current->next = pHead2;
			current = current->next;
			pHead2 = pHead2->next;
		}
	}
	return merge;
}
*/
//题目描述
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//解题思路
//1.树首选递归。
//2.一棵树是否为另一棵树的子结构，判断根节点、左子树、右子树是否都相等。

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    static bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL)//tree2遍历完成，依然相等，返回true
            return true;
        if(pRoot1 == NULL)//tree2遍历未完成，但tree1已完成遍历，返回false
            return false;
        if(pRoot1->val == pRoot2->val)//如果根节点相等，则递归判断左右子树是否相等
            return isSubtree(pRoot1->left,pRoot2->left) 
                    && isSubtree(pRoot1->right,pRoot2->right);
        else
            return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL)
            return false;
        return isSubtree(pRoot1,pRoot2) ||	//以此根节点为起点，判断是否为子树
               HasSubtree(pRoot1->left,pRoot2) || //以左孩子为起点，寻找左子树是否有子树
               HasSubtree(pRoot1->right,pRoot2); //以右孩子为起点，寻找右子树是否有子树
    }
};
/*
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
*/
class Solution2 {
public:
    static void swapTree(TreeNode *pRoot)//交换左右子树
    {
        if(pRoot == NULL)
            return;
        TreeNode *temp = pRoot->right;
        pRoot->right = pRoot->left;
        pRoot->left = temp;
    }
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)
            return;
        swapTree(pRoot);//交换根节点的左右子树
        Mirror(pRoot->left);//递归交换左子树
        Mirror(pRoot->right);//递归交换右子树
    }
};

class Solution3 {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.empty())
            return {}；
        vector<int> prin
        int lineNum = matrix.size();
        int rowNum = matrix[0].size();
        int size = lineNum * rowNum;
        int num  = 0;
        int i = 0,j = 0;
        while(lineNum)
        {
            while(j < rowNum)
            {
                
            }
        }
    }
};
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

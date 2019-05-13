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

/*
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 ，
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
解题思路：
定义矩阵的每一个循环的打印范围，即左上角元素、右下角的位置，为了防止重复打印（即出现单行单列），在打印下行与左列时判断是否为单行单列
*/
class Solution3 {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.empty())
		return{};
	vector<int> res;
	int lineNum = matrix.size();
	int rowNum = matrix[0].size();
	int left = 0, top = 0;//左上
	int bottom = lineNum - 1,right = rowNum - 1;//右下
	int i;
	while (left <= right && top <= bottom)
	{
		for (i = left; i <= right; ++i)
			res.push_back(matrix[top][i]);
		for (i = top + 1; i <= bottom; ++i)
			res.push_back(matrix[i][right]);
		for (i = right - 1; i >= left && top != bottom; --i)
			res.push_back(matrix[bottom][i]);
		for (i = bottom - 1; i > top && left != right; --i)
			res.push_back(matrix[i][left]);
		left++, top++, right--, bottom--;
	}
	return res;
    }
};

/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
解题思路
定义一个辅助栈，存放最小值；定义一个目标栈，一般意义上的栈。
入栈：目标栈正常入栈。当入栈元素小于等于辅助栈栈顶元素时，将入栈元素压入辅助栈，否则，不压入辅助栈；辅助栈为空时，元素压入辅助栈
出栈：目标栈栈顶元素等于辅助栈栈顶元素时，辅助栈出栈。目标栈正常出栈。
*/
class Solution4 {
public:
    void push(int value) {
        objStack.push(value);
        if(minStack.empty()) minStack.push(value);
        if(value <= minStack.top()) minStack.push(value);
    }
    void pop() {
        if(minStack.top() == objStack.top())
            minStack.pop();
        objStack.pop();
    }
    int top() {
        return objStack.top();
    }
    int min() {
        return minStack.top();
    }
private:
    stack<int> minStack;
    stack<int> objStack;
};
/*
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
解题思路
借助一个辅助栈，将压入顺序压入辅助栈，然后比较辅助栈栈顶元素与弹出顺序是否相等，如果相等，则辅助栈pop，弹出顺序数组右移一位，否则，进入下一个循环
继续向辅助栈压入进栈顺序。
*/
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

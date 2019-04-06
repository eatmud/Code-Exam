#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <sstream>

using namespace std;
void coutVector(vector<vector<int>> &v);
void coutVector(list<list<int>> &v);
void coutVector(vector<int> &v);
void coutVector(list<int> &v);

void coutVector(vector<vector<int>> &v)
{
	if (v.empty())
		cout << "vector is empty!" << endl;
	vector<vector<int>>::iterator lineIter;
	vector<int>::iterator rowIter;
	vector<int> temp;
	for (lineIter = v.begin(); lineIter != v.end(); ++lineIter)
	{
		temp = *lineIter;
		for (rowIter = temp.begin(); rowIter != temp.end(); ++rowIter)
			cout << *rowIter << " ";
		cout << endl;
	}
}
void coutVector(list<list<int>> &v)
{
	if (v.empty())
		cout << "vector is empty!" << endl;
	list<list<int>>::iterator lineIter;
	list<int>::iterator rowIter;
	list<int> temp;
	for (lineIter = v.begin(); lineIter != v.end(); ++lineIter)
	{
		temp = *lineIter;
		for (rowIter = temp.begin(); rowIter != temp.end(); ++rowIter)
			cout << *rowIter << " ";
		cout << endl;
	}
}
void coutVector(vector<int> &v)
{
	if (v.empty())
		cout << "vector is empty!" << endl;
	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}
void coutVector(list<int> &v)
{
	if (v.empty())
		cout << "vector is empty!" << endl;
	list<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << ",";
	cout << endl;
}

int main()
{
	list<list<int>> data;//存放输入的数组
	list<int> row;      //存放输入的行数组
	list<int> output;	//输出链表	
	list<list<int>>::iterator lineIter;
	list<list<int>>::iterator tempIter;
	list<int>::iterator rowIter;
	int value;
	int n;
	cin >> n;
	cin.get();
	//cout << n << endl;
	while (cin)
	{
		cin >> value;
		row.push_back(value);
		if (cin.get() == '\n')
		{
			data.push_back(row);
			row.clear();
		}
	}
	int i = 0;
	while (!data.empty())
	{
		for (lineIter = data.begin(); lineIter != data.end(); ++lineIter)
		{
			if (lineIter == data.end())//迭代器到达末尾，退出循环
			{
				cout << "break" << endl;
				break;
			}
			if (i == n || i == 0)//计数已达n，则归零，初始化时也归零
				i = 0;
			if ((*lineIter).empty())			//判断行是否为空
			{									//此时迭代器为头部，清除元素后，退出循环
				if (lineIter == data.begin())
				{
					data.erase(lineIter);
					//cout << "empty.begin" << endl;
					break;
				}
				else							// 若不为头部，则暂存当前迭代器的前一个位置，将当前元素删除，
				{								// 迭代器赋值为前迭代器的前一个位置，进入下一个循环
					tempIter = (--lineIter);
					data.erase(++lineIter);
					lineIter = tempIter;
					//cout << "empty.other" << endl;
					continue;
				}
			}
			for (rowIter = (*lineIter).begin(); rowIter != (*lineIter).end() && i < n; ++i)
			{
				output.push_back(*rowIter);
				//cout << "i= " << i << " value= " << *rowIter << endl;
				(*lineIter).pop_front();
				if (!(*lineIter).empty())			//删除首元素后，行不为空，获取新list的首元素，进入下一个循环
					rowIter = (*lineIter).begin();
				else
				{									//删除首元素后，行为空,计数加1，退出循环
					++i;
					break;
				}
			}
			//cout << "output : ";
			//coutVector(output);
		}
	}
	coutVector(output);
	return 0;
}
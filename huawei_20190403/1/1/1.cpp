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
	list<list<int>> data;//������������
	list<int> row;      //��������������
	list<int> output;	//�������	
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
			if (lineIter == data.end())//����������ĩβ���˳�ѭ��
			{
				cout << "break" << endl;
				break;
			}
			if (i == n || i == 0)//�����Ѵ�n������㣬��ʼ��ʱҲ����
				i = 0;
			if ((*lineIter).empty())			//�ж����Ƿ�Ϊ��
			{									//��ʱ������Ϊͷ�������Ԫ�غ��˳�ѭ��
				if (lineIter == data.begin())
				{
					data.erase(lineIter);
					//cout << "empty.begin" << endl;
					break;
				}
				else							// ����Ϊͷ�������ݴ浱ǰ��������ǰһ��λ�ã�����ǰԪ��ɾ����
				{								// ��������ֵΪǰ��������ǰһ��λ�ã�������һ��ѭ��
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
				if (!(*lineIter).empty())			//ɾ����Ԫ�غ��в�Ϊ�գ���ȡ��list����Ԫ�أ�������һ��ѭ��
					rowIter = (*lineIter).begin();
				else
				{									//ɾ����Ԫ�غ���Ϊ��,������1���˳�ѭ��
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
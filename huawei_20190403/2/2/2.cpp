#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
const int moveSize = 10;
void coutVector(vector<string> &v);
void moveLeft(string&, int);//字符串循环左移n位
void moveLeftData(vector<string>& data);//字符串数组循环左移n位
void stringTrim(vector<string>& data);//去重，将空格/制表/换行/回车 换成空格
void sortData(vector<string>& data);//字符串排序
void deletMark(string& s, string mark);//删除字符串的某个字符
void deletDataMark(vector<string>& data, string mark);//删除某一个字符
void intputData(vector<string>& data, vector<string>& legalData, vector<string>& illegalData);
//将输入的数据分别存入合法字符串数组与非法字符串数组

void coutVector(vector<string> &v)
{
	if (v.empty())
		cout << "vector is empty!" << endl;
	vector<string>::iterator iter;
	for (iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}
}
void moveLeft(string& s, int n)
{//字符串循环左移n位
	if (s.empty() || n <= 0)
		return;
	int length = s.size();
	n %= length;
	if (!n)
		return;
	reverse(s.begin(), s.begin() + n);
	//cout << s << endl;
	reverse(s.begin() + n, s.end());
	//cout << s << endl;
	reverse(s.begin(), s.end());
}
void moveLeftData(vector<string>& data)
{
	if (data.empty())
		cout << "vector is empty!" << endl;
	vector<string>::iterator iter;
	for (iter = data.begin(); iter != data.end(); ++iter)
	{
		moveLeft(*iter, moveSize);
	}
}
void stringTrim(vector<string>& data)
{//去重，将空格/制表/换行/回车 换成空格
	vector<string>::iterator iter;
	string::iterator sIter;
	string s;
	int n = 0;//计数器
	for (iter = data.begin(); iter != data.end(); ++iter)
	{
		s = (*iter);			//先将字符串删除，然后将处理后的字符串重新填回来
		(*iter).clear();
		for (sIter = s.begin(); sIter != s.end(); ++sIter)
		{
			if ((*sIter >= '0' && *sIter <= '9') || (*sIter >= 'a' && *sIter <= 'z') ||
				(*sIter >= 'A' && *sIter <= 'Z'))
			{
				if (-1 == (*iter).find(*sIter))//去重
				{
					(*iter) += (*sIter);
					n = 0;//读取到字符，则空字符串不连续，计数器置零
				}
			}
			else
			{
				n++;
				if (n > 1)//连续空格，则舍弃
				{
					continue;
					n = 0;
				}
				(*iter) += ' ';//换成空格
			}
				 				
		}
		s.clear();
	}
}
void sortData(vector<string>& data)
{//字符串排序
	if (data.empty())
		cout << "vector is empty!" << endl;
	vector<string>::iterator iter;
	for (iter = data.begin(); iter != data.end(); ++iter)
	{
		sort((*iter).begin(), (*iter).end());
	}
}
void deletMark(string& s, string mark)
{//删除字符串的某个字符
	size_t length = mark.size();
	size_t pos;
	while (1)
	{
		pos = s.find(mark);
		if (pos == string::npos)
			return;
		s.erase(pos, length);
	}
}
void deletDataMark(vector<string>& data, string mark)
{
	if (data.empty())
		cout << "vector is empty!" << endl;
	vector<string>::iterator iter;
	for (iter = data.begin(); iter != data.end(); ++iter)
	{
		deletMark(*iter,mark);
	}
}
void intputData(vector<string>& data,vector<string>& legalData,vector<string>& illegalData)
{//将输入的数据分别存入合法字符串数组与非法字符串数组
	bool legal;//判断字符串是否合法
	string legalString = "";
	vector<string>::iterator iter;
	string::iterator sIter;
	for (iter = data.begin(); iter != data.end(); ++iter)
	{
		for (sIter = (*iter).begin(); sIter != (*iter).end(); ++sIter)
		{
			legal = (*sIter >= '0' && *sIter <= '9') || (*sIter >= 'a' && *sIter <= 'z') ||
				(*sIter >= 'A' && *sIter <= 'Z') || *sIter == ' ' || *sIter == '\n' || *sIter == '\t' ||
				*sIter == '\r';
			if (!legal)
			{
				illegalData.push_back(*iter);
				break;
			}

			else
			{
				continue;
			}
		}
		if (legal)
			legalData.push_back(*iter);
		legalString.clear();
	}
}
int main()
{
	vector<string> data;
	vector<string> legalData;
	vector<string> illegalData;
	string line;
	while (getline(cin, line))
	{
		data.push_back(line);
		line.clear();
	}
	cout << "data : " << endl;
	coutVector(data);
	cout << endl << endl;

	intputData(data,legalData,illegalData);
	

	cout << "legalData :" << endl;
	coutVector(legalData);
	cout << endl << endl;


	cout << "illegalData :" << endl;
	coutVector(illegalData);
	cout << endl << endl;


	stringTrim(legalData);
	cout << "legalData trim:" << endl;
	coutVector(legalData);
	cout << endl << endl;


	moveLeftData(legalData);
	cout << "legalData moveLeft:" << endl;
	coutVector(legalData);
	cout << endl << endl;


	deletDataMark(legalData," " );
	sortData(legalData);
	cout << "legalData sort:" << endl;
	coutVector(legalData);

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
const int moveSize = 10;
void coutVector(vector<string> &v);
void moveLeft(string&, int);//�ַ���ѭ������nλ
void moveLeftData(vector<string>& data);//�ַ�������ѭ������nλ
void stringTrim(vector<string>& data);//ȥ�أ����ո�/�Ʊ�/����/�س� ���ɿո�
void sortData(vector<string>& data);//�ַ�������
void deletMark(string& s, string mark);//ɾ���ַ�����ĳ���ַ�
void deletDataMark(vector<string>& data, string mark);//ɾ��ĳһ���ַ�
void intputData(vector<string>& data, vector<string>& legalData, vector<string>& illegalData);
//����������ݷֱ����Ϸ��ַ���������Ƿ��ַ�������

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
{//�ַ���ѭ������nλ
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
{//ȥ�أ����ո�/�Ʊ�/����/�س� ���ɿո�
	vector<string>::iterator iter;
	string::iterator sIter;
	string s;
	int n = 0;//������
	for (iter = data.begin(); iter != data.end(); ++iter)
	{
		s = (*iter);			//�Ƚ��ַ���ɾ����Ȼ�󽫴������ַ������������
		(*iter).clear();
		for (sIter = s.begin(); sIter != s.end(); ++sIter)
		{
			if ((*sIter >= '0' && *sIter <= '9') || (*sIter >= 'a' && *sIter <= 'z') ||
				(*sIter >= 'A' && *sIter <= 'Z'))
			{
				if (-1 == (*iter).find(*sIter))//ȥ��
				{
					(*iter) += (*sIter);
					n = 0;//��ȡ���ַ�������ַ���������������������
				}
			}
			else
			{
				n++;
				if (n > 1)//�����ո�������
				{
					continue;
					n = 0;
				}
				(*iter) += ' ';//���ɿո�
			}
				 				
		}
		s.clear();
	}
}
void sortData(vector<string>& data)
{//�ַ�������
	if (data.empty())
		cout << "vector is empty!" << endl;
	vector<string>::iterator iter;
	for (iter = data.begin(); iter != data.end(); ++iter)
	{
		sort((*iter).begin(), (*iter).end());
	}
}
void deletMark(string& s, string mark)
{//ɾ���ַ�����ĳ���ַ�
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
{//����������ݷֱ����Ϸ��ַ���������Ƿ��ַ�������
	bool legal;//�ж��ַ����Ƿ�Ϸ�
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
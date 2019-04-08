#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<vector<int>> data;
	vector<int> row;
	vector<float> mid;
	vector<int> coffeeMachineV;
	int n1 = 0;
	int n2 = 0;
	int peopleNum;
	int coffeeMachineNum;
	int cleanMachineV;
	int selfCleanV;
	int t = 0;
	int value;
	int num;
	cin >> num;
	cin.get();
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
	coffeeMachineV = data[1];
	peopleNum = data[0][0];
	coffeeMachineNum = data[0][1];
	cleanMachineV = data[0][2];
	selfCleanV = data[0][3];
	sort(coffeeMachineV.begin(), coffeeMachineV.end());

	t = coffeeMachineV[0] + data[0][2];

	while ((n1 + n2) < peopleNum)
	{
		int time;
		n1 = 0;
		n2 = 0;
		if ((t - selfCleanV) >= 0)
		{
			for (int i = 0; i < coffeeMachineNum; ++i)
			{
				n1 += (t - selfCleanV) / coffeeMachineV[i];
			}

			 time = t - selfCleanV + 1;
		}
		else
		{
			n1 = 0;
			time = 0;
		}
		for (;time < t;++time)
		{
			int ntemp = 0;
			for (int j = 0; j < coffeeMachineNum; ++j)
			{
				if (0 == time % coffeeMachineV[j])
					++ntemp; 
			}
			cout << "mid : ";
			for (int i = 0; i < mid.size(); ++i)
				cout << mid[i] << " ";
			cout << endl;
			mid.push_back(ntemp);
		}
		float m = 0.0;
		for (int j = 0; j < mid.size() - 1; ++j)
		{
			if (mid[j] * 1.0 >= 1.0 / cleanMachineV)
			{
				m += 1.0 / cleanMachineV;
				mid[j + 1] += mid[j] * 1.0 - 1.0 / cleanMachineV;
			}
		}
		if (mid[mid.size() - 1] >= 1.0 / cleanMachineV)
			m += 1.0 / cleanMachineV;
		n2 += m;
		for (int i = 0; i < mid.size(); ++i)
			cout << mid[i] << " ";
		cout << endl;
		mid.clear();
		t++;
		cout << "time : " << t-1 << " " << n1 << " " << n2 << endl;
	}
	cout << t - 1;
	return 0;
}
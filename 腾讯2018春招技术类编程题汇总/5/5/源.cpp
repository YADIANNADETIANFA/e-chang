/*#include<iostream>//仅仅30%，存在问题：可能顶级机器的工作时间很长，但其等级却很低，从而导致它卡掉了许多本可以和别的机器匹配的任务
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Mission 
{
	int time;
	int level;
};

struct Machine
{
	int time;
	int level;
};

bool compare_mission(Mission a, Mission b)
{
	if (a.time > b.time)
		return true;
	else if (a.time == b.time && a.level > b.level)
		return true;
	else
		return false;
}

bool compare_machine(Machine a, Machine b)
{
	if (a.time > b.time)
		return true;
	else if (a.time == b.time && a.level > b.level)
		return true;
	else
		return false;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<Machine> machine;
		vector<Mission> mission;
		for (int i = 0; i < n; ++i)
		{
			int zi, wi;
			cin >> zi >> wi;
			Machine one_machine;
			one_machine.time = zi;
			one_machine.level = wi;
			machine.push_back(one_machine);
		}
		for (int i = 0; i < m; ++i)
		{
			int xi, yi;
			cin >> xi >> yi;
			Mission one_mission;
			one_mission.time = xi;
			one_mission.level = yi;
			mission.push_back(one_mission);
		}

		sort(machine.begin(), machine.end(), compare_machine);
		sort(mission.begin(), mission.end(), compare_mission);

		int finish_num=0;
		int get_money=0;
		int machine_index = 0;

		for (int i = 0; i < m; ++i)
		{
			if (machine_index < n)
			{
				while (machine_index < n && machine[machine_index].time >= mission[i].time && machine[machine_index].level >= mission[i].level)
				{
					machine_index++;
					finish_num++;
					get_money += (200 * mission[i].time + 3 * mission[i].level);
				}
			}
			else
				break;
		}

		cout << finish_num << ' ' << get_money << endl;
	}
	return 0;
}*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Mission
{
	int time;
	int level;
};

struct Machine
{
	int time;
	int level;
	bool isuseful = true;
};

bool compare_mission(Mission a, Mission b)
{
	if (a.time > b.time)
		return true;
	else if (a.time == b.time && a.level > b.level)
		return true;
	else
		return false;
}

bool compare_machine(Machine a, Machine b)
{
	if (a.time > b.time)
		return true;
	else if (a.time == b.time && a.level > b.level)
		return true;
	else
		return false;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<Machine> machine;
		vector<Mission> mission;
		for (int i = 0; i < n; ++i)
		{
			int zi, wi;
			cin >> zi >> wi;
			Machine one_machine;
			one_machine.time = zi;
			one_machine.level = wi;
			machine.push_back(one_machine);
		}
		for (int i = 0; i < m; ++i)
		{
			int xi, yi;
			cin >> xi >> yi;
			Mission one_mission;
			one_mission.time = xi;
			one_mission.level = yi;
			mission.push_back(one_mission);
		}

		sort(machine.begin(), machine.end(), compare_machine);
		sort(mission.begin(), mission.end(), compare_mission);

		int finish_num = 0;
		int get_money = 0;

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (machine[j].isuseful == true && machine[j].time >= mission[i].time && machine[j].level >= mission[i].level)
				{
					machine[j].isuseful = false;
					finish_num++;
					get_money += (200 * mission[i].time + 3 * mission[i].level);
					break;
				}
			}
		}

		cout << finish_num << ' ' << get_money << endl;
	}
	return 0;
}
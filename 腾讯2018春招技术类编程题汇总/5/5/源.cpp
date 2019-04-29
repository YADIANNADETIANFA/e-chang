/*小Q的公司最近接到m个任务, 第i个任务需要xi的时间去完成, 难度等级为yi。
小Q拥有n台机器, 每台机器最长工作时间zi, 机器等级wi。
对于一个任务,它只能交由一台机器来完成, 如果安排给它的机器的最长工作时间小于任务需要的时间, 则不能完成,如果完成这个任务将获得200 * xi + 3 * yi收益。
对于一台机器,它一天只能完成一个任务, 如果它的机器等级小于安排给它的任务难度等级, 则不能完成。
小Q想在今天尽可能的去完成任务, 即完成的任务数量最大。如果有多种安排方案,小Q还想找到收益最大的那个方案。小Q需要你来帮助他计算一下。
/*#include<iostream>//仅仅30%，存在问题：可能顶级机器的工作时间很长，但其等级却很低，从而导致它卡掉了许多本可以和别的机器匹配的任务*/
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

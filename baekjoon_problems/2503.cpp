#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[10];
int group[3];
vector<int> v;

void makegroup(int cnt)
{
	if (cnt == 3)
	{
		int num = group[0] * 100 + group[1] * 10 + group[2];
		v.push_back(num);
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (visited[i] == false)
		{
			group[cnt] = i;
			visited[i] = true;
			makegroup(cnt + 1);
			group[cnt] = 0;
			visited[i] = false;
		}
	}
}

bool check(int number,int cmp,int s,int b)
{
	int n1 = number / 100, n2 = (number % 100) / 10, n3 = (number % 100) % 10;
	int o1 = cmp / 100, o2 = (cmp% 100) / 10, o3 = (cmp% 100) % 10;
	int stCnt = 0;
	int bCnt = 0;

	if (n1 == o1) { stCnt++; }
	if (n2 == o2) { stCnt++; }
	if (n3 == o3) { stCnt++; }

	if (o1 == n2 || o1 == n3) { bCnt++; }
	if (o2 == n1 || o2 == n3) { bCnt++; }
	if (o3 == n1 || o3 == n2) { bCnt++; }

	if (stCnt == s && bCnt == b)
		return true;

	return false;
}
int main()
{
	int n;
	cin >> n;
	vector<int> q;
	vector<int> s;
	vector<int> b;
	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		q.push_back(x);
		s.push_back(y);
		b.push_back(z);

	}
	makegroup(0);

	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int num = v[i];
		for (int j = 0; j < n; j++)
		{
			if (check(num, q[j], s[j], b[j]) == false)
			{
				ans++;
				break;
			}
		}
	}

	cout << v.size() - ans;

	return 0;
}
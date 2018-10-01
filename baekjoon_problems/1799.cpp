#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
int arr[10][10];
bool visited[10][10];
int ans[2];
bool check(int y, int x)
{
	int tmp = 0;
	while (0 <= y - tmp && y - tmp < n &&
			0 <= x - tmp && x - tmp < n)
	{
		if (visited[y - tmp][x - tmp] == true)
			return false;
		tmp++;
	}

	tmp = 0;
	while (0 <= y - tmp && y - tmp < n &&
			0 <= x + tmp && x + tmp < n)
	{
		if (visited[y - tmp][x + tmp] == true)
			return false;
		tmp++;
	}

	return true;
}

void calc(int ver)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (visited[i][j])
				cnt++;

	ans[ver] = max(ans[ver], cnt);
	return;
}
void makegroup(int row, int depth,int ver)
{
	if (depth >= n)
	{
		if (row == n-1)
		{
			calc(ver);
			return;
		}

		row++;

		if (ver == 0)
		{
			if (row % 2 == 0)
				depth = 0;
			else
				depth = 1;
		}
		else
		{
			if (row % 2 == 0)
				depth = 1;
			else
				depth = 0;
		}

		makegroup(row, depth, ver);// 다음 줄 호출
		return;
	}

	if (arr[row][depth] == 1)		// 비숍 놓을수 있는 자리.
	{
		if (check(row, depth))
		{
			visited[row][depth] = true;			// 비숍 놓고 dfs 
			makegroup(row, depth + 2, ver);
			visited[row][depth] = false;
		}

	}

	makegroup(row, depth + 2, ver);		// 비숍 안놓고 dfs

	return;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	memset(visited, false, sizeof(visited));
	makegroup(0, 0, 0);//0 = black

	memset(visited, false, sizeof(visited));
	makegroup(0, 1, 1);//1 = white

	cout << ans[0] + ans[1] << endl;
	return 0;
}

#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct info {
	int y;
	int x;
	info(int _y, int _x) :
		y(_y), x(_x) {};
};
int arr[51][51];
bool check[51][51];
int n, m;

int dy[4] = { 0,-1,0,1 }; // 서 북 동 남
int dx[4] = { -1,0,1,0 };
int mask[4] = { 14,13,11,7 };

int bfs(int i, int j)
{
	queue<info> q;
	q.push(info(i, j));
	check[i][j] = true;
	int size = 0;
	
	while (!q.empty())
	{
		info cur = q.front();
		q.pop();
		size++;
		int y = cur.y;
		int x = cur.x;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if ((arr[y][x] >> i) % 2 == 1) //가는 방향쪽으로 벽이이씀.
				continue;

			if (0 <= ny && ny < m && 0 <= nx && nx < n)
			{
				if (check[ny][nx] == false)
				{
					q.push(info(ny, nx));
					check[ny][nx] = true;
				}
			}

		}
	}

	return size;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	
	int cnt = 0;// 방의 갯수
	int maxsize = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] == false)
			{
				cnt++;
				maxsize = max(maxsize, bfs(i, j));
			}
		}

	memset(check, false, sizeof(check));

	int maxsumsize = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
//			memset(check, false, sizeof(check));
			int tmp = arr[i][j];
			for (int k = 0; k < 4; k++)	// 동서남북 벽 없앰 처리
			{
				memset(check, false, sizeof(check));

				arr[i][j] = arr[i][j] & mask[k];
				maxsumsize = max(maxsumsize, bfs(i, j));
				arr[i][j] = tmp;
			}

		}
	printf("%d\n%d\n%d\n", cnt, maxsize, maxsumsize);
	return 0; 
}
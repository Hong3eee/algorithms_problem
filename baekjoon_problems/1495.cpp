#include <cstdio>
#include <algorithm>

using namespace std;

bool d[101][1001];
int arr[102];
int main()
{
	int n, s, m;
	scanf("%d %d %d", &n, &s, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	d[0][s] = true;	// 처음 볼륨 설정

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
		{
			if (d[i - 1][j] == true)
			{
				int dest = j + arr[i];
				if (0 <= dest && dest <= m)
					d[i][dest] = true;

				dest = j - arr[i];
				if (0 <= dest && dest <= m)
					d[i][dest] = true;
			}
		}

	int ans = -1;
	for (int j = 0; j <= m; j++)
	{
		if (d[n][j] == true)
			ans = max(ans, j);
	}

	printf("%d\n", ans);
	return 0;
}
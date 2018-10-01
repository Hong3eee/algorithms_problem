#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);

	for (int i = 1; i <= 7980; i++)
	{
		int x = i % 15;// == 0 ? 1 : i % 16;
		int y = i % 28;// == 0 ? 1 : i % 29;
		int z = i % 19;// == 0 ? 1 : i % 20;
		if (x == e-1 && y == s-1 && z == m-1)
		{
			printf("%d\n", i%7980+1);
			break;
		}
	}

	return 0;
}
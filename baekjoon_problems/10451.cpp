#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

vector<int> v[1001];
bool check[1001];

void dfs(int x)
{
	check[x] = true;
	int next = v[x][0];
	if(check[next]==false)
		dfs(next);
}
int main(){

	int t,n;

	scanf("%d",&t);

	for(int z=0;z<t;z++)
	{
		scanf("%d",&n);

		for(int i=1;i<=n;i++)
			v[i].clear();

		memset(check,false,sizeof(check));

		for(int i=1;i<=n;i++)
		{
			int edge;
			scanf("%d",&edge);
			v[i].push_back(edge);
		}
		int cnt = 0 ;

		for(int i = 1; i<=n;i++)
		{
			if(check[i]==false)
			{
				cnt++;
				dfs(i);
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

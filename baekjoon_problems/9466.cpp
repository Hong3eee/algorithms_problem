#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int check[100001];
int group[100001];
vector<int> a[100001];

int dfs(int x,int cnt,int g){ 
	int y = a[x][0];
	if(group[y] !=0 && group[y] != g)
		return 0;
	if(check[x] != 0)
		return cnt - check[x];
	check[x] = cnt;
	group[x] = g;
	return dfs(y,cnt+1,g);
}

int main(){
	int t;
	scanf("%d",&t);

	for(int z = 0 ; z<t;z++)
	{
		int n;
		scanf("%d",&n);
		for(int i =1; i<=n; i++){
			a[i].clear();
			check[i] = 0;
			group[i] = 0;
		}

		for(int i = 1; i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			a[i].push_back(x);
		}
		int tot = 0;
		for(int i = 1; i<=n;i++)
		{
			if(check[i] == 0 )
				tot += dfs(i,1,i);
		}
		printf("%d\n",n - tot);
	}
}

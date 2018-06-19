#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[1001];
bool check[1001];
int cnt;

void dfs(int x)
{
	check[x] = true;
	for(int i = 0 ;i < v[x].size();i++)
	{
		int next = v[x][i];
		if(check[next]==false)
			dfs(next);
	}
}
int main(){

	int n,m;
	scanf("%d %d",&n,&m);

	for(int i=1;i<=m;i++)
	{
		int node,node2;
		scanf("%d %d",&node,&node2);
		v[node].push_back(node2);
		v[node2].push_back(node);
	}

	for(int i = 1; i<=n;i++)
	{
		if(check[i]==false)
		{
			dfs(i);
			cnt++;
		}
	}

	printf("%d\n",cnt);

//	for(int i=1;i<=m;i++)
//		for(int j=0;j<v[i].size();j++)
//			printf("%d %d\n",i,v[i][j]);

	return 0;

}

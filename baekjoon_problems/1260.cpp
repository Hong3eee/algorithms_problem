#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

bool check[1001];
vector<int> v[1001];

void dfs(int x){ 
	check[x] = true;
	printf("%d ",x);
	for(int i =0;i<v[x].size();i++){
		int y =v[x][i];
		if(check[y] == false)
		{
			dfs(y);
		}
	}   
}

void bfs(int x){ 
	queue<int> q;
	memset(check,false,sizeof(check));
	check[x] = true;
	q.push(x);

	while(!q.empty()) {
		int top = q.front();
		q.pop();
		printf("%d ",top);
		for(int i = 0;i<v[top].size();i++){
			int y = v[top][i];
			if(check[y] == false)
			{
				check[y] = true;
				q.push(y);
			}
		}

	}

}
int main(){
	int n,m,start;
	scanf("%d %d %d",&n,&m,&start);

	for(int i =0; i<m ; i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1; i<=n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(start);
	puts("");
	bfs(start);
	puts("");
	return 0;
}


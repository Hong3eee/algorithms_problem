#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

char arr[50][50];
int check[50][50];

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int m,n;
int ans;

void bfs(int y,int x){
	memset(check,0,sizeof(check));
	queue<pair<int,int> > q;
	q.push(make_pair(y,x));
	check[y][x] = 1;

	while(!q.empty()){
		pair<int,int> cur = q.front();
		q.pop();

		for(int i=0;i<4;i++)
		{
			int nexty = cur.first + dy[i];
			int nextx = cur.second + dx[i];

			if(0<= nexty && nexty <n && 0 <= nextx && nextx < m)
				if(arr[nexty][nextx] == 'L' && check[nexty][nextx] == 0)
				{
					q.push(make_pair(nexty,nextx));
					check[nexty][nextx] = check[cur.first][cur.second] + 1;
					if(ans < check[nexty][nextx])
						ans = check[nexty][nextx];
				}
		}
	}
	return ;
}

int main(){
	scanf("%d %d",&n,&m);
	char s[50][50];

	for(int i=0;i<n;i++)
		scanf("%s",s[i]);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			arr[i][j] = s[i][j];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(arr[i][j] == 'L')
				bfs(i,j);

	printf("%d\n",ans == 0 ? 0 : ans-1);
	
	return 0;
}

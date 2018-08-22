#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int arr[1000][1000];
int check[2][1000][1000]; //상태 2개 저장

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

struct info{
	int y,x,s;
	info(int _y,int _x,int _s): 
		y(_y),x(_x),s(_s) {};
};

int m,n;
void bfs(int y,int x,int status){ //status = 0 벽아직 안뚫, = 1 뚫
	queue<info> q;
	q.push(info(y,x,status));
	check[status][y][x] = 1;

	while(!q.empty()){
		info cur = q.front();
		q.pop();
		int y = cur.y;
		int x = cur.x;
		int s = cur.s;

		for(int i=0;i<4;i++)
		{
			int nexty = y + dy[i];
			int nextx = x + dx[i];

			if(0<= nexty && nexty <n && 0 <= nextx && nextx < m)
			{
				if(arr[nexty][nextx] == 1 && s == 0)//벽을 부수지 않은 상태에서 벽을 만나면 부순다.
					//다른 부수지 않는 노드에 의해서 다시 부서져도 최단경로를 찾기 때문에 에러 X
				{
					check[s+1][nexty][nextx] = check[s][y][x] + 1;
					q.push(info(nexty,nextx,s+1));
				}
				else if(arr[nexty][nextx] == 0 && check[s][nexty][nextx] == 0)
				{
					//벽이 아니라면 상태를 유지하며 계속 진행
					q.push(info(nexty,nextx,s));
					check[s][nexty][nextx] = check[s][y][x] + 1;

				}
			}
		}
	}
	return ;
}

int main(){
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%1d",&arr[i][j]);

	bfs(0,0,0);

	int ans =987654321;
	for(int s=0;s<2;s++)
		if(check[s][n-1][m-1] > 0)
			ans = min(ans,check[s][n-1][m-1]);

	printf("%d\n",ans == 987654321? -1 :ans);

	return 0;
}

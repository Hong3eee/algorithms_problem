#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int arr[200][200];
int check[31][200][200]; //상태 K개 저장

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int dy2[8] = {2,1,-1,-2,-2,-1,1,2};
int dx2[8] = {1,2,2,1,-1,-2,-2,-1}; // 스킬이동

struct info{
	int y,x,s;
	info(int _y,int _x,int _s): 
		y(_y),x(_x),s(_s) {};
};

int k,w,h;
void bfs(int y,int x,int status){ 
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

			if(0<= nexty && nexty <h && 0 <= nextx && nextx < w)
			{
				if(arr[nexty][nextx] == 0 && check[s][nexty][nextx] == 0)
				{
					q.push(info(nexty,nextx,s));
					check[s][nexty][nextx] = check[s][y][x] + 1;
				}
			}
		}

		if(s < k)	//스킬 사용
		{
			for(int i=0;i<8;i++)
			{
				int nexty = y + dy2[i];
				int nextx = x + dx2[i];

				if(0<= nexty && nexty <h && 0 <= nextx && nextx < w)
				{
					if(arr[nexty][nextx] == 0 && check[s+1][nexty][nextx] == 0 && s < k)
					{
						check[s+1][nexty][nextx] = check[s][y][x] + 1;
						q.push(info(nexty,nextx,s+1));
					}
				}

			}
		}
	}
	return ;
}

int main(){
	scanf("%d %d %d",&k,&w,&h);

	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			scanf("%1d",&arr[i][j]);

	bfs(0,0,0);

	for(int s=0;s<=k;s++)
	{
		puts("d");
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
				printf("%d ",check[s][i][j]);
			puts("");
		}
	}
	
	int ans =987654321;
	for(int s=0;s<=k;s++)
		if(check[s][h-1][w-1] > 0)
			ans = min(ans,check[s][h-1][w-1]);

	printf("%d\n",ans == 987654321? -1 :ans -1);

	return 0;
}

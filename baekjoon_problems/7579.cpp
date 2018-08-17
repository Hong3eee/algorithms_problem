#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int direction[6][3] ={ 	// z,y,x 순
	{0,1,0},
	{0,0,1},
	{0,-1,0},
	{0,0,-1},
	{1,0,0},
	{-1,0,0} };

struct vertex {
	int z,y,x;
};

int check[101][101][101];
int arr[101][101][101];
int m,n,h;
queue<vertex> q;

void bfs(){

	while(!q.empty())
	{
		vertex cur = q.front();
		q.pop();

		for(int i=0;i<6;i++)
		{
			vertex next;
			int nextz = cur.z + direction[i][0];
			int nexty = cur.y + direction[i][1];
			int nextx = cur.x + direction[i][2];

			if( (0 <nextx && nextx <= m) 
					&& (0 <nexty && nexty <= n)
					&& (0 <nextz && nextz <= h) 
			  )
			{
				if( arr[nextz][nexty][nextx] == 0
						&& check[nextz][nexty][nextx] == 0)
				{
					check[nextz][nexty][nextx] = check[cur.z][cur.y][cur.x] + 1;
					next.x = nextx;
					next.y = nexty;
					next.z = nextz;

					q.push(next);
				}
			}
		}
	}
	return;
}
int main(){
	cin >> m >> n >> h;

	for(int z=1;z<=h;z++)
		for(int y=1;y<=n;y++)
			for(int x=1;x<=m;x++)
			{
				scanf("%d",&arr[z][y][x]);
				if(arr[z][y][x] == 1)
				{
					check[z][y][x] = 1;
					vertex v;
					v.z = z;
					v.y = y;
					v.x = x;
					q.push(v);
				}
			}

		bfs();

		int ans = 0;

	for(int z=1;z<=h;z++)
	{
		for(int y=1;y<=n;y++)
		{
			for(int x=1;x<=m;x++)
			{
				if(check[z][y][x] == 0 && arr[z][y][x] ==0)
				{
					printf("%d\n",-1);
					return 0;
				}
				ans = max(ans,check[z][y][x]);
				printf("%d ",check[z][y][x]);
			}
			puts("");
		}
		puts("");
		puts("");
	}

	printf("%d\n",ans-1);


	return 0;
}

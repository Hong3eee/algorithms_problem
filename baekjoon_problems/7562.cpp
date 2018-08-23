#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int arr[301][301];
int check[301][301]; 

int dy[8] = {2,1,-1,-2,-2,-1,1,2};
int dx[8] = {1,2,2,1,-1,-2,-2,-1}; 

struct info{
	int y,x;
	info(int _y,int _x): 
		y(_y),x(_x) {};
};

int t,l;
int bfs(int sy,int sx,int toy,int tox){ 
	queue<info> q;
	q.push(info(sy,sx));
	check[sy][sx] = 1;

	while(!q.empty()){
		info cur = q.front();
		q.pop();
		int y = cur.y;
		int x = cur.x;

		for(int i=0;i<8;i++)
		{
			int nexty = y + dy[i];
			int nextx = x + dx[i];

			if(0<= nexty && nexty <l && 0 <= nextx && nextx < l)
			{
				if(arr[nexty][nextx] == 0 && check[nexty][nextx] == 0)
				{
					q.push(info(nexty,nextx));
					check[nexty][nextx] = check[y][x] + 1;
				}
				if(nexty == toy && nextx == tox)
					return check[toy][tox];
			}
		}

	}
	return check[toy][tox];
}

int main(){
	scanf("%d",&t);
	for(int z=0;z<t;z++)
	{
		memset(check,0,sizeof(check));
		scanf("%d",&l);

		int sy,sx,toy,tox;
		scanf("%d %d",&sx,&sy);
		scanf("%d %d",&tox,&toy);

		printf("%d\n",bfs(sy,sx,toy,tox)-1);
	}

	return 0;
}

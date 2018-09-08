#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int w,h;

char map[105][105];
int check[3][105][105];

int dy[4] = { 1,0,-1,0};
int dx[4] = { 0,1,0,-1};

struct info{
	int y,x;
	info(int _y,int _x):
		y(_y),x(_x) {};
};

int bfs(int sy,int sx,int who)
{
	queue<info> q;
	q.push(info(sy,sx));
	check[who][sy][sx] = 0;

	while(!q.empty())
	{	
		int y = q.front().y;
		int x = q.front().x;

		q.pop();

		for(int i = 0; i<4;i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if( 0 <= ny && ny < h+2 && 0 <= nx && nx < w+2)
			{
				if( (map[ny][nx] == '.'||map[ny][nx] =='$') && (check[who][ny][nx] == -1 || check[who][ny][nx] > check[who][y][x] ))
				{
					check[who][ny][nx] = check[who][y][x];
					q.push(info(ny,nx));
				}
				else if(map[ny][nx] == '#' && (check[who][ny][nx] == -1 ||check[who][ny][nx] > check[who][y][x]+1 ))
				{
					check[who][ny][nx] = check[who][y][x] + 1;
					q.push(info(ny,nx));
				}

			}
		}
	}
	return 0;
}

int main(){
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++)
	{
		scanf("%d %d",&h,&w);

		memset(map,'\0',sizeof(map));
		memset(check,-1,sizeof(check));
		vector<info> v;

		for(int i=0;i<=h+1;i++)
			for(int j=0;j<=w+1;j++)
				map[i][j] = '.';

		for(int i=1;i<h+1;i++)
		{
			scanf("%s",map[i]+1);
			for(int j=1;j<=w;j++)
				if(map[i][j] == '$')
					v.push_back(info(i,j));
			map[i][w+1] = '.';
		}

		v.push_back(info(0,0));

		for(int i=0;i<v.size();i++)
			bfs(v[i].y,v[i].x,i);

		int ans = 987654321;

		/*
		for(int i=0;i<h+2;i++)
			printf("%s\n",map[i]);
	
		for(int k=0;k<v.size();k++)
		{
			puts("delimi");
			for(int i=0;i<h+2;i++)
			{
				for(int j=0;j<w+2;j++)
				{
					printf("%d ",check[k][i][j]);
				}
				puts("");
			}
		}
		*/
	/*	for(int i=0;i<h+2;i++)
		{
			for(int j=0;j<w+2;j++)
			{
				int sum=0;
				if(map[i][j] == '*') {
					printf("x ");
					continue;
				}

				for(int k=0;k<v.size();k++)
					sum = sum + check[k][i][j];

				printf("%d ",sum);

			}
			puts("");
		}
*/

		for(int i=0;i<h+2;i++)
		{
			for(int j=0;j<w+2;j++)
			{
				int sum=0;
				if(map[i][j] == '*') continue;

				for(int k=0;k<v.size();k++)
					sum = sum + check[k][i][j];
				if(map[i][j] == '#') 
					sum = sum - 2;

		//		sum = sum -3;

				ans = min(ans,sum);
			}
		}

		printf("%d\n",ans);
	}

	return 0;
}

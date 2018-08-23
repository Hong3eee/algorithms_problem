#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int w,h;


char arr[1001][1001];
int check[1001][1001];
int fcheck[1001][1001];

int dy[4] = { 1,0,-1,0};
int dx[4] = { 0,1,0,-1};

struct info{
	int y,x;
	info(int _y,int _x):
		y(_y),x(_x) {};
};

queue<info> fireq;
queue<info> q;

void bfs()
{
	while(!q.empty())
	{	
		// 불먼저
		/*
		   puts("check arr");

		   for(int i=0;i<h;i++)
		   {
		   for(int j = 0 ;j<w;j++)
		   printf("%d",check[i][j]);
		   puts("");
		   }
		   puts("map arr");

		   for(int i=0;i<h;i++)
		   {
		   for(int j = 0 ;j<w;j++)
		   printf("%c",arr[i][j]);
		   puts("");
		   }
		 */

		int fqlen = fireq.size();
		while(fqlen--)
		{
			int y = fireq.front().y;
			int x = fireq.front().x;

			fireq.pop();

			for(int i = 0; i<4;i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if( 0 <= ny && ny < h && 0 <= nx && nx < w)
				{
					if(arr[ny][nx] != '#' && fcheck[ny][nx] == 0)
					{
						arr[ny][nx] = '*';
						fcheck[ny][nx] = -1;
						fireq.push(info(ny,nx));
					}
				}
			}
		}

		// 상근이 나중에
		int qlen = q.size();
		while(qlen--)
		{
			int y = q.front().y;
			int x = q.front().x;

			q.pop();	
			if(y == 0 || y == h-1 || x == 0 || x == w-1)
			{
				printf("%d\n",check[y][x]);

				return;
			}


			for(int i = 0; i<4;i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if( 0 <= ny && ny < h && 0 <= nx && nx < w)
				{
					if(arr[ny][nx] == '.' && check[ny][nx] == 0)// && fcheck[ny][nx] == 0)
					{
						check[ny][nx] = check[y][x] + 1;
						/*
						if(ny == 0 || ny == h-1 || nx == 0 || nx == w-1)
						{
							//				printf("ny = %d nx = %d check = %d \n",ny,nx,check[ny][nx]);
							printf("%d\n",check[ny][nx]);

							return;
						}
						*/
						q.push(info(ny,nx));
					}
				}
			}
		}

	}
	printf("IMPOSSIBLE\n");
	return ;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int z=0;z<t;z++)
	{
		memset(arr,0,sizeof(arr));
		memset(check,0,sizeof(check));
		memset(fcheck,0,sizeof(fcheck));

		while(!q.empty())
			q.pop();

		while(!fireq.empty())
			fireq.pop();

		scanf("%d %d",&w,&h);
		for(int i=0;i<h;i++)
		{
			scanf("%s",arr[i]);
			for(int j = 0 ;j<w;j++)
			{
				if(arr[i][j] == '@')
				{
					q.push(info(i,j));
					check[i][j] = 1;
				}
				else if(arr[i][j] == '*')
				{
					fcheck[i][j] = -1;
					fireq.push(info(i,j));
				}
			}
		}

		bfs();
	}
	return 0;
}

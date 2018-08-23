#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int w,h;

char arr[1001][1001];
int check[1001][1001];

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
					if(arr[ny][nx] == '.' || arr[ny][nx] == 'J')
					{
						arr[ny][nx] = 'F';
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

			for(int i = 0; i<4;i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if( 0 <= ny && ny < h && 0 <= nx && nx < w)
				{
					if(arr[ny][nx] == '.' && check[ny][nx] == 0)// && fcheck[ny][nx] == 0)
					{
						check[ny][nx] = check[y][x] + 1;
						q.push(info(ny,nx));
					}
				}
			}
		}

	}
	return ;
}

int main(){
	memset(arr,'\0',sizeof(arr));
	memset(check,0,sizeof(check));

	vector<info> v;

	scanf("%d %d",&h,&w);
	for(int i=0;i<h;i++)
	{
		scanf("%s",arr[i]);
		for(int j = 0 ;j<w;j++)
		{
			if(i == 0 || i == h-1 || j == 0 || j == w-1)
				if(arr[i][j] == '.'||arr[i][j] == 'J')
					v.push_back(info(i,j));
			if(arr[i][j] == 'J')
			{
				q.push(info(i,j));
				check[i][j] = 1;
			}
			else if(arr[i][j] == 'F')
				fireq.push(info(i,j));
		}
	}

	bfs();

	int ans = 987654321;
	for(int i = 0 ; i < v.size() ; i++)
	{
		if( check[v[i].y][v[i].x] > 0)
			ans = min(ans,check[v[i].y][v[i].x]);
	}

	if(ans == 987654321)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n",ans);



	return 0;
}

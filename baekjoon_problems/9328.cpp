#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int w,h;

char arr[101][101];
int check[101][101];
int keys[26];

int dy[4] = { 1,0,-1,0};
int dx[4] = { 0,1,0,-1};

struct info{
	int y,x;
	info(int _y,int _x):
		y(_y),x(_x) {};
};

queue<info> doorq;
queue<info> q;
int ans;

void door_check()
{
	int len = doorq.size();
	while(len--)
	{
		info front = doorq.front();
		int y = front.y;
		int x = front.x;

		char c = arr[y][x];

		if(keys[c - 'A'] == 1)
		{
			arr[y][x] = '.';
			check[y][x] = 1;

			q.push(info(y,x));
			doorq.pop();
		}
		else
		{
			doorq.pop();
			doorq.push(front);
		}
	}
	return;
}
void bfs()
{
	door_check();

	while(!q.empty())
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
				if(arr[ny][nx] == '.' && check[ny][nx] == 0)
				{
					check[ny][nx] = 1;
					q.push(info(ny,nx));
				}
				else if(arr[ny][nx] == '$')
				{
					ans++;
					arr[ny][nx] = '.';
					check[ny][nx] = 1;
					q.push(info(ny,nx));
				}
				else if(arr[ny][nx] != '*')
				{
					if('A' <=arr[ny][nx] && arr[ny][nx] <= 'Z')
					{
						doorq.push(info(ny,nx));
						door_check();
					}
					if('a' <=arr[ny][nx] && arr[ny][nx] <= 'z')
					{
						keys[arr[ny][nx] - 'a'] = 1;
						arr[ny][nx] = '.';
						check[ny][nx] = 1;
						q.push(info(ny,nx));
						door_check();
					}
				}

			}
		}
	}
	return ;
}

int main(){
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++)
	{
		ans = 0;
		scanf("%d %d",&h,&w);

		while(!doorq.empty())
			doorq.pop();

		memset(arr,'\0',sizeof(arr));
		memset(check,0,sizeof(check));
		memset(keys,0,sizeof(keys));

		for(int i=0;i<h;i++)
			scanf("%s",arr[i]);


		char input[1000];

		scanf("%s",input);
		for(int i =0;i<strlen(input);i++)
			keys[input[i] - 'a'] = 1;

		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				if(i == 0 || i == h-1 || j == 0 || j == w-1)
				{
					if(arr[i][j] == '.')
					{
						check[i][j] = 1;
						q.push(info(i,j));
					}
					else if(arr[i][j] == '$')
					{
						arr[i][j] = '.';
						check[i][j] = 1;
						ans++;
						q.push(info(i,j));
					}
					else if(arr[i][j] != '*')
					{
						if('A' <=arr[i][j] && arr[i][j] <= 'Z')
							doorq.push(info(i,j));
						if('a' <=arr[i][j] && arr[i][j] <= 'z')
						{
							keys[arr[i][j] - 'a'] = 1;
							arr[i][j] = '.';
							check[i][j] = 1;
							q.push(info(i,j));
						}
					}
				}
			}

			bfs();
			printf("%d\n",ans);
	}

	return 0;
}

#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int check[20][100001];
int dx[2] = {-1,1};

int n,k;
struct info{
	int x,s;
	info(int _x,int _s):
		x(_x),s(_s) {};
};


void bfs(int start,int status)
{
	queue<info> q;
	q.push(info(start,status));
	check[status][start] = 1;

	while(!q.empty())
	{
		int x = q.front().x;
		int s = q.front().s;
		q.pop();

		for(int i =0;i<2;i++)
		{
			int nx = x + dx[i];

			if(0<= nx && nx <= 100000)
			{
				if(check[s][nx] == 0)
				{
					check[s][nx] = check[s][x] + 1;
					q.push(info(nx,s));
				}
			}
		}

		int nx = 2 * x;

		if(0< nx && nx <= 100000 && s < 19)
		{
			if(check[s+1][nx] == 0)
			{
				check[s+1][nx] = check[s][x] + 1;
				q.push(info(nx,s+1));
			}
		}


	}
	return ;
}

int main(){
	scanf("%d %d",&n,&k);

	bfs(n,0);
	int ans = 987654321;
	for(int i = 0 ; i<20 ; i++)
	{
		if(check[i][k] > 0)
			ans = min(ans,check[i][k]);
	}

	int cnt = 0;
	for(int i = 0 ; i<20 ; i++)
		printf("i %d check %d \n",i, check[i][k]);
//		if(ans == check[i][k])
//			cnt++;
	printf("%d\n",ans -1);
	printf("%d\n",cnt);

	return 0;
}

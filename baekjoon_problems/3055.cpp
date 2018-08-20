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

int r,c;
int ans = 987654321;
int desty,destx;

queue<pair<int,int> > wq;
queue<pair<int,int> > sq;

void water_bfs(){
	int wqsize = wq.size();
	while(wqsize-- > 0){
		int y = wq.front().first;
		int x = wq.front().second;

		wq.pop();

		for(int i=0;i<4;i++)
		{
			int nexty = y + dy[i];
			int nextx = x + dx[i];

			if(0<= nexty && nexty <r && 0 <= nextx && nextx < c)
				if(arr[nexty][nextx] == '.' && check[nexty][nextx] == 0)
				{
					arr[nexty][nextx] = '*';
					wq.push(make_pair(nexty,nextx));
					check[nexty][nextx] = -1;
				}
		}
	}
	return ;
}
void bfs(){
	while(!sq.empty()){

		water_bfs();

		int sqsize = sq.size();
		while(sqsize-- > 0){
			int y = sq.front().first;
			int x = sq.front().second;

			sq.pop();

			for(int i=0;i<4;i++)
			{
				int nexty = y + dy[i];
				int nextx = x + dx[i];

				if(0<= nexty && nexty <r && 0 <= nextx && nextx < c)
					if(arr[nexty][nextx] == '.' && check[nexty][nextx] == 0)
					{
						sq.push(make_pair(nexty,nextx));
						check[nexty][nextx] = check[y][x] + 1;
					}
					else if(arr[nexty][nextx] == 'D' && check[nexty][nextx] ==0)
						check[nexty][nextx] = check[y][x] + 1;
			}
		}
	}
}

int main(){
	scanf("%d %d",&r,&c);
	char input[50][50];

	for(int i=0;i<r;i++)
		scanf("%s",input[i]);

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			arr[i][j] = input[i][j];
			if(arr[i][j] == '*')
			{
				check[i][j] = -1;
				wq.push(make_pair(i,j));
			}
			else if(arr[i][j] == 'S')
			{
				check[i][j] = 1;
				sq.push(make_pair(i,j));
			}
			else if(arr[i][j] == 'D')
			{
				desty = i;
				destx = j;
			}
		}
	}

	bfs();

	if(check[desty][destx]==0)
		printf("KAKTUS\n");
	else
		printf("%d\n",check[desty][destx] - 1);
	return 0;
}

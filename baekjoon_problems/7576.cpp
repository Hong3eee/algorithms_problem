#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int weight[1000][1000];
int arr[1000][1000];
int n,m;

queue< pair<int,int> > q;

void bfs(){

	while(!q.empty()){
		int first = q.front().first;
		int second = q.front().second;
		q.pop();

		for(int k=0;k<4;k++)	//방향 배열 사용
		{
			int x,y;
			x = first+dx[k];
			y = second+dy[k];
			if( (x>=0 && x<n) && (y>=0 && y<m) )
			{
				if(arr[y][x] == 0 && weight[y][x] == -1)
				{
					weight[y][x] = weight[second][first]+1;
					q.push(make_pair(x,y));
				}
			}
		}
	}
}

int main(){
	memset(weight,-1,sizeof(weight));
	scanf("%d %d",&n,&m);

	for(int y=0;y<m;y++)
	{
		for(int x=0;x<n;x++)
		{
			int z;
			scanf("%d",&z);
			arr[y][x] = z;
		}

	}

	for(int y=0;y<m;y++)
	{
		for(int x=0;x<n;x++)
		{
			if(arr[y][x] == 1)
			{
				weight[y][x] = 0;//방문
				q.push(make_pair(x,y));
			}
		}
	}

	bfs();

	int maxvalue=-1;
	bool check = false;
	for(int y=0;y<m;y++){
		for(int x=0;x<n;x++)
		{
			if(weight[y][x] == -1 && arr[y][x] != -1)
				check =true;
				
//			printf("%d ",weight[y][x]);
		}
//		printf("\n");
	}

	for(int y=0;y<m;y++)
		for(int x=0;x<n;x++)
		{
			if(weight[y][x] >= maxvalue)
				maxvalue = weight[y][x];
		}


	printf("%d\n",check ?-1: maxvalue);

	return 0;
}

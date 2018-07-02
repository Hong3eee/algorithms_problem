#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int weight[100][100];
int group[100][100];
int arr[100][100];
int n;
int group_cnt;
int minValue=987654321;

queue< pair<int,int> > q;
void bfs_makegroup(int firstx,int firsty){

	group[firsty][firstx] = group_cnt;
	q.push(make_pair(firstx,firsty));

	while(!q.empty()){
		int first = q.front().first;
		int second = q.front().second;
		q.pop();

		for(int k=0;k<4;k++)	//방향 배열 사용
		{
			int x,y;
			x = first+dx[k];
			y = second+dy[k];
			if( (x>=0 && x<n) && (y>=0 && y<n) )
			{
				if(arr[y][x] == 1 && group[y][x] == 0)
				{
					group[y][x] = group_cnt;
					q.push(make_pair(x,y));
				}
			}
		}
	}
}
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
			if( (x>=0 && x<n) && (y>=0 && y<n) )
			{
				if(arr[y][x] == 0) {
					if (group[y][x] == 0)
					{
						group[y][x] = group[second][first];
						weight[y][x] = weight[second][first]+1;
						q.push(make_pair(x,y));
					}
					else if(group[y][x] != group[second][first])
					{
						int tmp = weight[y][x] + weight[second][first];

						if( tmp < minValue )
							minValue = tmp;
					}
				}
			}
		}
	}
}

int main(){
	scanf("%d",&n);

	for(int y=0;y<n;y++)
		for(int x=0;x<n;x++)
		{
			int z;
			scanf("%d",&z);
			arr[y][x] = z;
		}

	for(int y=0;y<n;y++)
		for(int x=0;x<n;x++)
			if(arr[y][x] == 1 && group[y][x] == 0)
			{
				group_cnt++;
				bfs_makegroup(x,y);
			}

	for(int y=0;y<n;y++)
		for(int x=0;x<n;x++)
			if(arr[y][x] == 1)
				q.push(make_pair(x,y));
	bfs();

	printf("%d\n",minValue);
	return 0;
}

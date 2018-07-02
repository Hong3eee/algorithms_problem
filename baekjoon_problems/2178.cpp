#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int weight[100][100];
int arr[100][100];
int n,m;

queue< pair<int,int> > q;

void bfs(int i,int j){
	weight[i][j] = 1;//방문
	q.push(make_pair(i,j));

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
				if(arr[x][y] == 1 && weight[x][y] == 0)
				{
					weight[x][y] = weight[first][second]+1;
					q.push(make_pair(x,y));
				}
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x;
			scanf("%1d",&x);
			arr[i][j] = x;
		}

	}

	bfs(0,0);

	printf("%d\n",weight[n-1][m-1]);
	return 0;
}

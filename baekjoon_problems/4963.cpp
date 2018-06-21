#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};

int group[50][50];
int arr[50][50];
int group_num;
int w,h;

queue< pair<int,int> > q;

void bfs(int i,int j){
	group[i][j] = group_num; //방문
	q.push(make_pair(i,j));

	while(!q.empty()){
		int first = q.front().first;
		int second = q.front().second;
		q.pop();

		for(int k=0;k<8;k++)	//방향 배열 사용
		{
			int x,y;
			x = first+dx[k];
			y = second+dy[k];
			if( (x>=0 && x<h) && (y>=0 && y<w) )
			{
				if(arr[x][y] == 1 && group[x][y] == 0)
				{
					group[x][y] = group_num;
					q.push(make_pair(x,y));
				}
			}
		}
	}
}

int main(){
	while(true)
	{
		scanf("%d %d",&w,&h);

		if(w==0&&h==0)
			return 0;

		memset(group,0,sizeof(group));
		memset(arr,0,sizeof(arr));
		group_num =0;

		for(int i = 0; i<h;i++){
			for(int j = 0;j<w;j++){
				int x;
				scanf("%d",&x);
				arr[i][j] = x;
			}
		}

		for(int i = 0; i<h;i++){
			for(int j = 0;j<w;j++){
				if(arr[i][j] == 1 && group[i][j] == 0){
					group_num++;
					bfs(i,j);
				}
			}
		}
		printf("%d\n",group_num);
	}
}

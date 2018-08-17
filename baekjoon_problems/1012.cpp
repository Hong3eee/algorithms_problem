#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int group[50][50];
int arr[50][50];
int group_num;
int m,n;

void dfs(int i,int j){
	group[i][j] = group_num; //방문

	for(int k=0;k<4;k++)	//상하좌우 방문할지 반복문 사용해서 검증
	{
		int x,y;
		y = i+dy[k];
		x = j+dx[k];
		if( (x>=0 && x<m) && (y>=0 && y<n) )
		{
			if(arr[y][x] == 1 && group[y][x] ==0)
				dfs(y,x);
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(int z=0;z<t;z++)
	{
		int k;
		group_num = 0;

		memset(arr,0,sizeof(arr));
		memset(group,0,sizeof(group));

		scanf("%d %d %d",&m,&n,&k);

		for(int i=0;i<k;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			arr[y][x] = 1;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(arr[i][j] != 0 && group[i][j] == 0){
					group_num++;
					dfs(i,j);
				}
			}
		printf("%d\n",group_num);
	}


	return 0;
}

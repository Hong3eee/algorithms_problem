#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int arr[8][8];
int tmp[8][8];
int group[8][8];
bool check[8][8];

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int m,n,ans;
int cnt;
void bfs(int,int);

void simul(){

	memset(check,false,sizeof(check));

	for(int i =0;i<n;i++)
	{
		for(int j =0;j<m;j++)
		{
			tmp[i][j] = arr[i][j];
			if(group[i][j] == 1)
				tmp[i][j] = 1;
		}
	}

	
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<m;j++)
			if(tmp[i][j] == 2 && check[i][j] == false)
				bfs(i,j);

	}

	int cnt = 0;

	for(int i =0;i<n;i++)
		for(int j =0;j<m;j++)
			if(tmp[i][j] == 0)
				cnt++;
	ans = max(ans,cnt);


	return ;
}


void solve(int lastidx,int size){

	if(size==3)
	{
		simul();
		return ;
	}

	for(int i = lastidx + 1 ; i < m * n ; i++)
	{
		int y = i / m;
		int x = i % m;

		if(arr[y][x] == 0) 
		{
			group[y][x] = 1;
			solve(i,size+1);
			group[y][x] = 0;
		}
	}

}

void bfs(int y,int x){
	queue<pair<int,int> > q;
	q.push(make_pair(y,x));
	check[y][x] = true;

	while(!q.empty()){
		pair<int,int> cur = q.front();
		q.pop();

		for(int i=0;i<4;i++)
		{
			int nexty = cur.first + dy[i];
			int nextx = cur.second + dx[i];

			if(0<= nexty && nexty <n && 0 <= nextx && nextx < m)
				if(tmp[nexty][nextx] == 0 && check[nexty][nextx] == false)
				{
					q.push(make_pair(nexty,nextx));
					check[nexty][nextx] = true;
					tmp[nexty][nextx] = 2;
				}
		}
	}
	return ;
}

int main(){
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&arr[i][j]);
	for(int i = 0 ; i < m * n ; i++)
	{
		int y = i / m;
		int x = i % m;

		if(arr[y][x] == 0) 
		{
			group[y][x] = 1;
			solve(i,1);
			group[y][x] = 0;
		}
	}

	printf("%d\n",ans);

	return 0;
}

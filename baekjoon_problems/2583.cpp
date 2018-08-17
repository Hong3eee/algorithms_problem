#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int arr[100][100];
bool check[100][100];

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int m,n,k;

int bfs(int y,int x){
	queue<pair<int,int> > q;
	q.push(make_pair(y,x));
	check[y][x] = true;

	int ret = 1;

	while(!q.empty()){
		pair<int,int> next = q.front();
		q.pop();

		for(int i=0;i<4;i++)
		{
			int nexty = next.first + dy[i];
			int nextx = next.second + dx[i];

			if( 0 <= nexty && nexty <m && 0 <= nextx && nextx < n)
			{
				if(arr[nexty][nextx] == 0 && check[nexty][nextx] == false)
				{
					check[nexty][nextx]=true;
					q.push(make_pair(nexty,nextx));
					ret ++;
				}
			}	
		}
	}

	return ret;
}

int main(){
	scanf("%d %d %d",&m,&n,&k);

	vector<int> v;
	for(int i=0;i<k;i++)
	{
		int startx,starty,endx,endy;
		scanf("%d %d %d %d",&startx,&starty,&endx,&endy);

		for(int y = starty; y<endy ; y++)
			for(int x = startx; x<endx ; x++)
				arr[y][x] = 1;
	}

	for(int y=0;y<m;y++)
		for(int x=0;x<n;x++)
			if(arr[y][x] == 0 && check[y][x] == false)
				v.push_back(bfs(y,x));

	sort(v.begin(), v.end());

	int vlen = v.size();
	printf("%d\n",vlen);

	for(int i =0;i<vlen;i++)
		printf("%d ",v[i]);
	puts("");

	return 0 ;
}

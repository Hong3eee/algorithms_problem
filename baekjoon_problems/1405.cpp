#include <cstdio>
#include <algorithm>

using namespace std;
int n;
double p[4];

bool map[30][30];

int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};

double dfs(int y,int x,int direction,int cnt)
{
	double ret = 0.0;

	if(map[y][x] == true)	// 계산 ㄴㄴ
		return 0.0;

	if(cnt == n)
		return p[direction];

	map[y][x] = true;

	for(int i =0;i<4;i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		ret = ret + p[direction] * dfs(ny,nx,i,cnt+1);
	}

	map[y][x] = false;

	return ret;
}
int main(){
	scanf("%d",&n);
	int tmp;
	for(int i=0;i<4;i++)
	{
		scanf("%d",&tmp);
		p[i] = tmp / 100.0;
	}

	double ans = 0.0;

	map[14][14] = true;

	for(int i=0;i<4;i++)
	{
		int ny = 14 + dy[i];
		int nx = 14 + dx[i];
	
		ans += dfs(ny,nx,i,1);
	}
	printf("%0.2f\n",ans);
	return 0;
}

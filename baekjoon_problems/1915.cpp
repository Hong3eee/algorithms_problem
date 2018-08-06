#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1001][1001];
int d[1001][1001];

int n,m;

// 재귀를 이용한 메모이제이션 패턴
int square(int y,int x)
{
	if(a[y][x] == 0)
		return 0;

	if(y == n || x == m)
		return a[y][x];

	int& ret = d[y][x];
	if(ret != -1) return ret;

	return ret = min(min(square(y+1,x) , square(y,x+1)),square(y+1,x+1))+1;
}
int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&a[i][j]);

	int ans = 0;
	memset(d,-1,sizeof(d));

	for(int y=1;y<=n;y++)
		for(int x=1;x<=m;x++)
			ans = max(ans,square(y,x));


	// 배열을 이용한 풀이
/*	for(int y=1;y<=n;y++)
		for(int x=1;x<=m;x++)
		{
			if(a[y][x] == 1)
			{
				int tmp = 987654321;
				tmp = min(tmp,d[y][x-1]);
				tmp = min(tmp,d[y-1][x-1]);
				tmp = min(tmp,d[y-1][x]);
				d[y][x] = tmp + 1;

				ans = max(ans,d[y][x]);
			}
		}
*/

	cout << ans*ans<<endl;
	return 0;
}


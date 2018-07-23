#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

double ans[100][50];
int a[50][50];
int q[50];
int connected[50];
int main(){

	int c;
	scanf("%d",&c);

	for(int z=0;z<c;z++)
	{
		int n,d,p;
		scanf("%d %d %d",&n,&d,&p);

		memset(ans,0.0,sizeof(ans));
		memset(connected,0,sizeof(connected));

		for(int y=0;y<n;y++)
		{
			int val=0;
			for(int x=0;x<n;x++)
			{
				scanf("%d",&a[y][x]);
				if(a[y][x] == 1)
					val++;
			}
			connected[y] = val;
		}

		int t;
		scanf("%d",&t);
		for(int i=0;i<t;i++)
			scanf("%d",&q[i]);

		ans[0][p] = 1.0;

		for(int i=0;i<d;i++)
			for(int j=0;j<n;j++)
			{
				if(ans[i][j] > 0.0) // 이 전에 있을 확률
					for(int k = 0; k<n;k++)
						if(a[j][k] == 1)	//연결되어있음
							ans[i+1][k] += ans[i][j] / connected[j];
			}

		for(int i = 0; i<t;i++)
			printf("%.8lf ",ans[d][ q[i] ]);

		puts("");
	}

	return 0;
}

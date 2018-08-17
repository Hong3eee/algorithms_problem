#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[501][501];
int n,m;

int cover[19][4][2] ={
	{ {0,0},{0,1},{0,2},{0,3} },
	{ {0,0},{1,0},{2,0},{3,0} }, // 막대기

	{ {0,0},{0,1},{1,0},{1,1} }, // 사각형

	{ {0,0},{1,0},{2,0},{2,1} }, 
	{ {0,0},{1,0},{0,1},{0,2} },
	{ {0,0},{0,1},{1,1},{2,1} },
	{ {0,0},{1,0},{1,-1},{1,-2} },
	{ {0,0},{1,0},{2,0},{2,-1} },
	{ {0,0},{1,0},{1,1},{1,2} },
	{ {0,0},{0,1},{1,0},{2,0} },
	{ {0,0},{0,1},{0,2},{1,2} }, // ㄱ꼴

	{ {0,0},{1,0},{1,1},{2,1} },
	{ {0,0},{0,1},{1,0},{1,-1} },
	{ {0,0},{1,0},{1,-1},{2,-1} },
	{ {0,0},{0,1},{1,1},{1,2} }, // ㄹ 꼴

	{ {0,0},{0,1},{0,2},{1,1} }, 
	{ {0,0},{1,0},{2,0},{1,1} }, 
	{ {0,0},{1,0},{1,1},{1,-1} }, 
	{ {0,0},{1,0},{2,0},{1,-1} } // ㅗ 꼴
};

int solve(int y,int x){
	int ret=0;

	for(int type=0;type<19;type++)
	{
		int tmpy=0,tmpx=0;
		bool check = true;
		int sum = 0;
		for(int i=0;i<4;i++)
		{
			tmpy = y + cover[type][i][0];
			tmpx = x + cover[type][i][1];

			if(tmpy > n || tmpy <1 || tmpx > m || tmpx < 1)
			{
				check = false;
				break;
			}

			sum += arr[tmpy][tmpx];
		}
		if(check == false) continue;

		ret = max(ret,sum);
//		printf("%d\n",ret);
	}
	return ret;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&arr[i][j]);

	int ans=0;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans = max(ans,solve(i,j));

	printf("%d\n",ans);

			return 0;
}

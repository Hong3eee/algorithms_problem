#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int arr[64][64];

void solve(int y,int x,int size)
{
	int ret;
	int comp = arr[y][x];
	bool check = true;

	if(size==1) {
		printf("%d",comp);
		return ;
	}

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(comp != arr[y+i][x+j])
				check = false;

	if(check)
	{
		printf("%d",comp);
		return ;
	}
	else
	{
		int half = size/2;
		printf("(");
		//	재귀
		solve(y,x,half);
		solve(y,x+half,half);
		solve(y+half,x,half);
		solve(y+half,x+half,half);
		printf(")");
	}
}

int main()
{
	int n;
	scanf("%d",&n);

	for(int y=0;y<n;y++)
		for(int x=0;x<n;x++)
			scanf("%1d",&arr[y][x]);

	solve(0,0,n);

	return 0;
}

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int cnt;
int n,r,c;

void solve(int y,int x,int size)
{
	if(y==r && x==c)
	{
		printf("%d\n",cnt);
		return ;
	}

	if( !( (y <= r && r <y+size) && (x <= c && c<x+size) ) ) //기저사례
	{
		cnt += size * size; 	//건너뛰는 칸들을 더해줌
		return ;
	}
	else
	{
		int half = size/2;
		//	재귀
		solve(y,x,half);
		solve(y,x+half,half);
		solve(y+half,x,half);
		solve(y+half,x+half,half);
	}
}
int main()
{
	scanf("%d %d %d",&n,&r,&c);
	solve(0,0,pow(2,n));
	return 0;
}

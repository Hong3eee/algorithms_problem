#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int n,l;
int arr[101][101];
int cnt;

vector<int> q[200];

bool visit[101];

bool check(int i,int j,int direction) // -1 방향 : <- , 1 방향: ->
{
	//  범위 넘어갔을때 처리 해줘야함

	if(direction == -1)
	{
		int cmp = q[i][j];
		for(int k=0;k<l;k++)
		{
			if( 0 > j-k || j-k >= n)
				return false;
			if(visit[j-k] == true)
				return false;

			int x = q[i][j-k];

			//		printf("i %d j %d cmp %d x %d\n",i,j,cmp,x);

			if(cmp == x)
				continue;
			else
				return false;
		}
	}
	else
	{
		int cmp = q[i][j+1];
		for(int k=0;k<l;k++)
		{
			if( 0 > j+1+k || j+1+k >= n)
				return false;
			int x = q[i][j+1+k];

			if(cmp == x)
				continue;
			else
				return false;
		}

		for(int k=0;k<l;k++)
			visit[j+1+k] = true;
	}


	return true;
}

int main(){
	scanf("%d %d",&n,&l);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&arr[i][j]);


	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			q[i].push_back(arr[i][j]);

	for(int j=0;j<n;j++)
		for(int i=0;i<n;i++)
			q[n + j].push_back(arr[i][j]);

	for(int i=0;i<2*n;i++)
	{
		int len = q[i].size();
		bool correct = true;
		memset(visit,false,sizeof(visit));
		for(int j =0;j< len-1 ;j++)
		{
			//1 2 -> 인덱스 앞쪽으로 경사로 두기
			//2 1 -> 인덱스 뒷쪽으로 경사로 두기

			if(q[i][j] != q[i][j+1])
			{
				int dir = q[i][j] - q[i][j+1];
				if(dir == 1)
				{
					correct = check(i,j,dir);
					if(correct == false)
						break;

				}
				else if(dir == -1)
				{
					correct = check(i,j,dir);
					if(correct == false)
						break;
				}
				else
				{
					correct = false;
					break;
				}


			}
			//			printf("%d ",q[i][j]);
		}
		if(correct == true)
		{
			//	printf("i  = %d \n ",i);
			cnt++;
		}
		//		puts("");
	}

	printf("%d\n",cnt);


	return 0;
}

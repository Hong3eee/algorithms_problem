#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
char arr[2200][2200];
int dx[3] = {-1,0,1};

void solve(int y,int x,int size)
{
	if(size == 1)
	{
		arr[y][x] = '*';
		return ;
	}

	int next = size/3;

	for(int i =0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(i==1&&j==1) continue;
			solve(y+dx[i]*next,x+dx[j]*next,next);
		}
}

int main()
{
	int n;
	scanf("%d",&n);
	memset(arr,' ',sizeof(arr));
	solve(n/2,n/2,n);

	for(int i =0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%c",arr[i][j]);

		printf("\n");
	}

	return 0;
}

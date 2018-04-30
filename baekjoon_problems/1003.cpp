#include <stdio.h>
#include <algorithm>
using namespace std;

int d[40][2];

int main(){

	int T;
	scanf("%d",&T);

	d[0][0] = 1;
	d[0][1] = 0;

	d[1][0] = 0;
	d[1][1] = 1;

	for(int i = 2; i<41;i++)
	{
		d[i][0] = d[i-1][0] + d[i-2][0] ;
		d[i][1] = d[i-1][1] + d[i-2][1] ;
	}

	for(int k = 0; k<T;k++)
	{
		int N;
		scanf("%d",&N);

		printf("%d %d\n",d[N][0],d[N][1]);
	}

	return 0;
}

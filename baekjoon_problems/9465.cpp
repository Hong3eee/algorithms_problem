#include <stdio.h>
#include <algorithm>

using namespace std;

int d[100001][3];
int p[100001][3];

int main(){

	int T,n;
	int tmpmax;
	scanf("%d",&T);

	for(int i =0;i<T;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<n+1;j++)
			scanf("%d",&p[j][1]);

		for(int j=1;j<n+1;j++)
			scanf("%d",&p[j][2]);

		d[1][0] = 0;
		d[1][1] = p[1][1];
		d[1][2] = p[1][2];

		for(int j=2;j<n+1;j++)
			for(int k=0;k<3;k++)
			{
				tmpmax = 0;
				for(int l=0;l<3;l++)
				{
					if( l == k)
						continue;
					tmpmax = max(tmpmax,d[j-1][l]);
				}
				d[j][k] = tmpmax + p[j][k];
			}

		printf("%d\n",max(d[n][0],max(d[n][1],d[n][2])));

	}

	return 0;
}

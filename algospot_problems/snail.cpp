#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

double d[1000][2001];
int main(){

	int c,n,m;

	scanf("%d",&c);
	for(int k =0;k<c;k++)
	{
		scanf("%d %d",&n,&m);
		memset(d,0,sizeof(d));

		d[0][1] = 0.25;
		d[0][2] = 0.75;

		for(int i =1;i<m;i++)
			for(int j =2;j<2*m+1;j++)
				d[i][j] = d[i-1][j-2] * 0.75 + d[i-1][j-1] * 0.25;

		double value = 0;
		for(int i = n;i<2*m+1;i++)
			value += d[m-1][i];

		printf("%.10lf \n",value);
	}

	return 0;
}

#include <stdio.h>
#include <algorithm>
using namespace std;

int a[501][501];
int d[501][501];

int main(){

	int n;
	scanf("%d",&n);

	for(int i = 1 ;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&a[i][j]);

	d[1][1] = a[1][1];

	for(int i = 2 ;i<=n;i++)
		for(int j=1;j<=i;j++)
			d[i][j] = max(d[i-1][j] , d[i-1][j-1]) + a[i][j]; 

	int maxValue=-1;
	for(int i =1;i<=n;i++)
		maxValue = max(maxValue,d[n][i]);

	printf("%d\n",maxValue);

	return 0;
}

#include <stdio.h>
#include <algorithm>

using namespace std;

int p[10001];
int d[10001][3];

int main(){

	int n;
	scanf("%d",&n);

	for(int i=1;i<n+1;i++)
		scanf("%d",&p[i]);

	for(int i=1;i<n+1;i++)
	{
		d[i][0] = max(d[i-1][0],max(d[i-1][1],d[i-1][2]));
		d[i][1] = d[i-1][0] + p[i];
		d[i][2] = d[i-1][1] + p[i];
	}

	printf("%d\n",max(d[n][0],max(d[n][1],d[n][2])));

	return 0;
}

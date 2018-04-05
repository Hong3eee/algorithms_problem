#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1001];
int d[1001];

int main(){
	int N;
	scanf("%d",&N);

	for(int i = 1; i<N+1;i++)
		scanf("%d",&a[i]);

	for(int i = 1; i<N+1;i++)
	{
		d[i] = a[i];
		for(int j = 1; j<i;j++)
		{
			if(a[i] > a[j] && d[i] < d[j] +a[i])
				d[i] = d[j] + a[i];
		}
	}

	int tmpmax =0;
	for(int i = 1; i<N+1;i++)
		tmpmax = max(tmpmax,d[i]);

	printf("%d\n",tmpmax);

	return 0;
}

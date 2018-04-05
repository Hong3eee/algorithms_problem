#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1001];
int d[1001];
int d2[1001];

int main(){
	int N;
	scanf("%d",&N);

	for(int i = 1; i<N+1;i++)
		scanf("%d",&a[i]);

	for(int i = 1; i<N+1;i++)
	{
		d[i] = 1;
		for(int j = 1; j<i;j++)
		{
			if(a[i] > a[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}
	for(int i = N; i>0;i--)
	{   
		d2[i] = 1;
		for(int j = N; j>i;j--)
		{
			if(a[i] > a[j] && d2[i] < d2[j] + 1)
				d2[i] = d2[j] + 1;
		}
	} 


	int tmpmax =0;
	for(int i = 1; i<N+1;i++)
		tmpmax = max(tmpmax,d[i]+d2[i]);

	printf("%d\n",tmpmax-1);

	return 0;
}

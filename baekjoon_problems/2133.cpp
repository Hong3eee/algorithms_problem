#include <stdio.h>
#include <algorithm>
using namespace std;

int d[31];

int main(){

	int N;
	scanf("%d",&N);

	d[0] = 1;

	for(int i =1;i<N+1;i++)
	{
		if(i%2 == 1)
		{
			d[i] = 0;
			continue;
		}
		d[i] = d[i-2];
		for(int j=1;j*2<=i;j++)
		{
			d[i] += 2*d[i-j*2];
		}
	//	printf("i= %d d[i]=%d\n",i,d[i]);
	}
	printf("%d\n",d[N]);

	return 0;
}

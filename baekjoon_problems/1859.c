#include <stdio.h>
#include <stdlib.h>

int main(){

	int T,N;
	long long int max;
	long long int sum;
	scanf("%d",&T);

	for (int i=0;i<T;i++)
	{
		scanf("%d",&N);
		long long int * arr = (long long int *)malloc(sizeof(long long int)*N);

		for(int j=0;j<N;j++)
			scanf("%lld",&arr[j]);

		max = 0;
		sum = 0;

		for(int j=N;j>0;j--)
		{
			if(max < arr[j-1])
				max = arr[j-1];
			else
				sum = sum + ( max - arr[j-1] );
		}
		printf("#%d %lld\n",i+1,sum);
	}
	return 0;
}

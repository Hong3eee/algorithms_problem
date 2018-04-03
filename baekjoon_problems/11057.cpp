#include <stdio.h>
#include <algorithm>

using namespace std;

int d[1001][10];

int main(){

	long long int mod = 10007;
	int N;
	scanf("%d",&N);

	for(int i = 0;i<10;i++)
		d[1][i] = 1;

	for(int i = 2;i<N+1;i++)
		for(int j = 0;j<10;j++)
		{
			for(int k=0;k<=j;k++)
				d[i][j] += d[i-1][k];

			d[i][j] %= mod;
		}

	long long int sum =0;
	for(int i = 0;i<10;i++)
		sum += d[N][i];

	printf("%lld\n",sum % mod);

	return 0;
}

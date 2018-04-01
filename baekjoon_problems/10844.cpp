#include <stdio.h>
#include <algorithm>

using namespace std;

int d[101][10];

int main(){

	long long int mod = 1000000000;
	int N;
	scanf("%d",&N);

	for(int i = 0;i<10;i++)
		d[1][i] = 1;
	d[1][0] = 0;

	for(int i = 2;i<N+1;i++)
		for(int j = 0;j<10;j++)
		{
			if(j==0)
				d[i][j] = d[i-1][j+1];
			else if(j==9)
				d[i][j] = d[i-1][j-1];
			else
				d[i][j] = d[i-1][j-1] + d[i-1][j+1];

			d[i][j] %= mod;
		}

	long long int sum =0;
	for(int i = 0;i<10;i++)
		sum += d[N][i];

	printf("%lld\n",sum % mod);

	return 0;
}

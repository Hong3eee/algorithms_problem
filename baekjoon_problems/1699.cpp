#include <stdio.h>
#include <algorithm>
using namespace std;

int d[100001];

int main(){

	int N;
	scanf("%d",&N);

	d[1] = 1;

	for(int i =1;i<N+1;i++)
	{
		int tmp = 100001;
		for(int j=1;j*j<=i;j++)
		{
			tmp = min(d[i-j*j]+1,tmp);
			d[i] = tmp;
		}
	}
	printf("%d\n",d[N]);

	return 0;
}

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

long long int d[5001];
int a[5001];
char s[5002];

int main(){

	scanf("%s",s+1);

	int len = strlen(s+1);

	for(int i =1;i<len+1;i++)
		a[i] = s[i] - '0';

	d[0] = 1 ;

	for(int i =1;i<len+1;i++)
	{
		if(1 <=a[i] && a[i]<=9 )
			d[i] = (d[i] + d[i-1]) % 1000000;
		if( i == 1)
			continue;
		if(a[i-1] == 0)
			continue;

		int x = a[i-1] * 10 + a[i] ;

		if(10<=x&&x<=26)
		{	
			d[i] = (d[i] + d[i-2]) % 1000000;
		}
	}

	printf("%lld\n",d[len]);

	return 0;
}

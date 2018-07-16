#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long int a[100];
long long int b[100];
long long int d[100];
long long int d2[100];

int main(){

	int c;
	scanf("%d",&c);

	for(int i =0;i<c;i++)
	{
		int n,m;
		scanf("%d %d",&n,&m);

		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		//			memset(d,1,sizeof(d));
		//			memset(d2,1,sizeof(d2)); // memset 은 0,-1 만 초기화가능 포스팅 ㄲ

		for(int j =0; j<n;j++)
			scanf("%lld",&a[j]);

		for(int j =0; j<m;j++)
			scanf("%lld",&b[j]);

		int ai=0,bi=0;

		for(int k = 0; k<n;k++)
		{
			d[k] = 1;
			for(int j = 0; j<k;j++)
			{
				if(a[k] > a[j] && d[k] < d[j] + 1)
					d[k] = d[j] + 1;
			}
		}

		for(int k = 0; k<m;k++)
		{
			d2[k] = 1;
			for(int j = 0; j<k;j++)
			{
				if(b[k] > b[j] && d2[k] < d2[j] + 1)
					d2[k] = d2[j] + 1;
			}

		}
		//	/*
		printf("A array\n");
		for(int j =0; j<n;j++)
			printf("%lld ",a[j]);
		puts("");

		printf("D array\n");
		for(int j =0; j<n;j++)
			printf("%lld ",d[j]);
		puts("");

		printf("B array\n");
		for(int j =0; j<m;j++)
			printf("%lld ",b[j]);
		puts("");

		printf("D2 array\n");
		for(int j =0; j<m;j++)
			printf("%lld ",d2[j]);
		puts("");
		puts("");
		//	 */
		while(ai < n && bi <m)
		{
			if(a[ai] <= b[bi])
			{
				for(int j = 0; j<m;j++)
				{
					if(a[ai] > b[j] && d[ai] < d2[j] + 1)
						d[ai] = d2[j] + 1;
				}
				for(int j = 0; j<ai;j++)
				{
					if(a[ai] > a[j] && d[ai] < d[j] + 1)
						d[ai] = d[j] + 1;
				}
				ai++;
			}
			else if(a[ai] > b[bi])
			{
				for(int j = 0; j<n;j++)
				{
					if(b[bi] > a[j] && d2[bi] < d[j] + 1)
						d2[bi] = d[j] + 1;
				}
				for(int j = 0; j<bi;j++)
				{
					if(b[bi] > b[j] && d2[bi] < d2[j] + 1)
						d2[bi] = d2[j] + 1;
				}
				bi++;
			}
		}
		if(ai == n)
		{
			while(bi!=m)
			{
				for(int j = 0; j<n;j++)
				{
					if(b[bi] > a[j] && d2[bi] < d[j] + 1)
						d2[bi] = d[j] + 1;
				}
				for(int j = 0; j<bi;j++)
				{
					if(b[bi] > b[j] && d2[bi] < d2[j] + 1)
						d2[bi] = d2[j] + 1;
				}
				bi++;


			}

		}
		else if(bi == m)
		{
			while(ai!=n)
			{
				for(int j = 0; j<m;j++)
				{
					if(a[ai] > b[j] && d[ai] < d2[j] + 1)
						d[ai] = d2[j] + 1;
				}
				for(int j = 0; j<ai;j++)
				{
					if(a[ai] > a[j] && d[ai] < d[j] + 1)
						d[ai] = d[j] + 1;
				}
				ai++;

			}

		}
		//	/*
		printf("A array\n");
		for(int j =0; j<n;j++)
			printf("%lld ",a[j]);
		puts("");

		printf("D array\n");
		for(int j =0; j<n;j++)
			printf("%lld ",d[j]);
		puts("");

		printf("B array\n");
		for(int j =0; j<m;j++)
			printf("%lld ",b[j]);
		puts("");

		printf("D2 array\n");
		for(int j =0; j<m;j++)
			printf("%lld ",d2[j]);
		puts("");
		//	*/

		long long int value = -1;
		for(int j = 0; j<n;j++)
		{
			if(d[j] > value)
				value = d[j];
		}

		for(int j = 0; j<m;j++)
		{
			if(d2[j] > value)
				value = d2[j];
		}
		printf("%lld\n",value);

	}



	return 0;
}

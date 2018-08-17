#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int len[50];
double t[50][50];
double d[1000001][50];
int want[10];

int main(){
	int c;
	cin >> c;
	for(int z = 0 ; z<c;z++)
	{
		memset(d,0,sizeof(d));
		int n,k,m;
		cin >> n >> k >> m;
		vector<double> ret(n);

		for(int i = 0;i<n;i++)
			cin >> len[i];


		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)
				cin >> t[i][j];

		for(int i = 0;i<m;i++)
			cin >> want[i];

		d[0][0] = 1.0;
		for(int i = len[0];i<=k;i++)
			for(int j = 0;j<n;j++)
			{
				double tmp = 0;
				for(int k=0;k<n;k++)
					d[i][j] += d[i-len[k]][k] * t[k][j];
			}

		for(int i = 0 ;i<n;i++)
			for(int t = k-len[i]+1;t<=k;t++)
				ret[i] += d[t][i];

		for(int i=0;i<m;i++)
			printf("%.8lf ", ret[want[i]]);

		puts("");


	}

	return 0;
}

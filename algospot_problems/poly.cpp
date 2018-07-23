#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int d[101][101];
int mod = 10000000;

int main(){
	int c;
	scanf("%d",&c);

	for(int z=0;z<c;z++)
	{
		memset(d,0,sizeof(d));
		int n;
		scanf("%d",&n);

		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
			{
				if(i==j)
					d[i][j] = 1;
				else
					for(int k=1;k<i;k++)
						d[i][j] = (d[i][j] +((j-1+k) * d[i-j][k])%mod)%mod;
			}

		int value =0;
		for(int i=1;i<=n;i++)
			value =(value + d[n][i] % mod)%mod;

		cout << value%mod << endl;
	}

	return 0;
}

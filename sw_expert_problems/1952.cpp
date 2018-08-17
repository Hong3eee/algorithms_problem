#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int z=1;z<=t;z++)
	{
		int day,mon1,mon3,year;
		scanf("%d %d %d %d",&day,&mon1,&mon3,&year);

		int table[13];
		int d[13] = {0,};
		for(int i=1;i<=12;i++)
			scanf("%d",&table[i]);

		for(int i=1;i<=12;i++)
		{
			int ret = 1000000;

			ret = min(ret, d[i-1] + table[i] * day);
			ret = min(ret, d[i-1] + mon1 );
			if(i>=3)
				ret = min(ret, d[i-3] + mon3 );
			d[i] = ret;

		}
		int ans = min(d[12] , year);

		printf("#%d %d",z,ans);
	}

	return 0;
}
